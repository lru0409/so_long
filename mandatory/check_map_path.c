/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:53:16 by rolee             #+#    #+#             */
/*   Updated: 2024/06/17 10:57:46 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_path	*init_path_data(t_game *game);
static int		init_visited(int map_size[], int **visited);
static void		check_path(t_game *game, t_path *path, int y, int x);
static void		clear_path_data(t_path *path, int map_size[]);

int	is_valid_path(t_game *game)
{
	t_path	*path;

	path = init_path_data(game);
	if (!path)
		return (FALSE);
	check_path(game, path, game->player[Y], game->player[X]);
	if (path->exit_count != 1 || path->item_count != game->total_item_count) {
		return (FALSE);
	}
	clear_path_data(path, game->map_size);
	return (TRUE);
}

static t_path	*init_path_data(t_game *game)
{
	t_path	*path;

	path = (t_path *)malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	path->map = game->map;
	path->exit_count = 0;
	path->item_count = 0;
	path->visited = NULL;
	path->visited = (int **)malloc(sizeof(int *) * game->map_size[HEIGHT]);
	if (!path->visited || init_visited(game->map_size, path->visited) == EXIT_FAILURE)
	{
		free(path->visited);
		free(path);
		return (NULL);
	}
	path->visited[game->player[Y]][game->player[X]] = TRUE;
	return (path);
}

static int	init_visited(int map_size[], int **visited)
{
	int	count;

	count = 0;
	while (count < map_size[HEIGHT])
	{
		visited[count] = (int *)malloc(sizeof(int) * map_size[WIDTH]);
		if (!visited[count])
		{
			while (count--)
				free(visited[count]);
			return (EXIT_FAILURE);
		}
		ft_memset(visited[count], FALSE, sizeof(int) * map_size[WIDTH]);
		count++;
	}
	return (EXIT_SUCCESS);
}

static void	check_path(t_game *game, t_path *path, int y, int x)
{
	int	index;
	int	ny;
	int	nx;

	if (path->map[y][x] == ITEM)
		path->item_count += 1;
	if (path->map[y][x] == EXIT)
		path->exit_count += 1;
	index = 0;
	while (index < 4)
	{
		ny = y + game->dir[Y][index];
		nx = x + game->dir[X][index];
		if (path->map[ny][nx] != WALL && !path->visited[ny][nx])
		{
			path->visited[ny][nx] = TRUE;
			check_path(game, path, ny, nx);
		}
		index++;
	}
	return ;
}

static void	clear_path_data(t_path *path, int map_size[])
{
	int	index;

	index = 0;
	while (index < map_size[HEIGHT])
		free(path->visited[index++]);
	free(path->visited);
	free(path);
}
