/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:53:16 by rolee             #+#    #+#             */
/*   Updated: 2024/06/07 19:37:39 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_path	*init_path_data(t_game *game);
static int		init_visited(int map_size[], int **visited);
static void	check_path(t_path *path, int y, int x);

int	is_valid_path(t_game *game)
{
	t_path	*path;

	path = init_path_data(game);
	if (!path)
		return (FALSE);
	check_path(path, game->player_pos[Y], game->player_pos[X]);
	if (path->exit_count != 1 || path->item_count != game->item_count)
		return (error(FALSE, "Invalid Map"));
	return (TRUE);
}

static t_path	*init_path_data(t_game *game)
{
	t_path	*path;

	path = (t_path *)malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	path->map = game->map;
	ft_memset(path->dir, 0, sizeof(path->dir));
	path->dir[Y][UP] = -1;
	path->dir[Y][DOWN] = 1;
	path->dir[X][LEFT] = -1;
	path->dir[X][RIGHT] = 1;
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
	path->visited[game->player_pos[Y]][game->player_pos[X]] = TRUE;
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

static void	check_path(t_path *path, int y, int x)
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
		ny = y + path->dir[Y][index];
		nx = x + path->dir[X][index];
		if (path->map[ny][nx] != WALL && !path->visited[ny][nx])
		{
			path->visited[ny][nx] = TRUE;
			check_path(path, ny, nx);
		}
		index++;
	}
	return ;
}
