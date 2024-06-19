/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:35:52 by rolee             #+#    #+#             */
/*   Updated: 2024/06/19 10:49:42 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangle(char **map, int map_size[]);
static int	is_surrounded_wall(char **map);
static int	is_valid_component(char **map, int *total_item_count, int player[]);
static int	check_compoenent(char c, int cep_count[]);

int	is_valid_map(t_game *game)
{
	if (is_rectangle(game->map, game->map_size) == FALSE)
		return (error(FALSE, "Map Is Not Rectangle."));
	if (is_surrounded_wall(game->map) == FALSE)
		return (error(FALSE, "Map Is Not Surrounded By Wall."));
	if (is_valid_component(game->map, &game->total_item_count, \
							game->player) == FALSE)
		return (error(FALSE, "Map Component Is Invalid."));
	if (is_valid_path(game) == FALSE)
		return (error(FALSE, "Map Path Is Invalid."));
	return (TRUE);
}

static int	is_rectangle(char **map, int map_size[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (map_size[WIDTH] == 0)
			map_size[WIDTH] = j;
		else if (map_size[WIDTH] != j)
			return (FALSE);
		i++;
	}
	map_size[HEIGHT] = i;
	return (TRUE);
}

static int	is_surrounded_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != WALL)
				return (FALSE);
			if (map[i + 1] == NULL && map[i][j] != WALL)
				return (FALSE);
			if (j == 0 && map[i][j] != WALL)
				return (FALSE);
			if (map[i][j + 1] == '\0' && map[i][j] != WALL)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	is_valid_component(char **map, int *total_item_count, int player[])
{
	int	cep_count[3];
	int	index[2];

	ft_memset(cep_count, 0, sizeof(cep_count));
	index[Y] = -1;
	while (map[++index[Y]])
	{
		index[X] = -1;
		while (map[index[Y]][++index[X]])
		{
			if (check_compoenent(map[index[Y]][index[X]], cep_count) == FALSE)
				return (FALSE);
			if (map[index[Y]][index[X]] == PLAYER)
			{
				player[Y] = index[Y];
				player[X] = index[X];
				map[index[Y]][index[X]] = EMPTY;
			}
		}
	}
	if (cep_count[0] < 1 || cep_count[1] != 1 || cep_count[2] != 1)
		return (FALSE);
	*total_item_count = cep_count[0];
	return (TRUE);
}

static int	check_compoenent(char c, int cep_count[])
{
	if (c != EMPTY && c != WALL && c != ITEM && c != EXIT && c != PLAYER)
		return (FALSE);
	if (c == ITEM)
		cep_count[0]++;
	else if (c == EXIT)
		cep_count[1]++;
	else if (c == PLAYER)
		cep_count[2]++;
	return (TRUE);
}
