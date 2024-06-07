/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:35:52 by rolee             #+#    #+#             */
/*   Updated: 2024/06/07 19:37:48 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangle(char **map, int map_size[]);
static int	is_surrounded_wall(char **map);
static int	is_valid_component(char **map, int *item_count, int player_pos[]);
static int	check_compoenent(char c, int cep_count[]);

int	is_invalid_map(t_game *game)
{
	if (is_rectangle(game->map, game->map_size) == FALSE)
		return (error(EXIT_FAILURE, "Invalid Map"));
	if (is_surrounded_wall(game->map) == FALSE)
		return (error(EXIT_FAILURE, "Invalid Map"));
	if (is_valid_component(game->map, &game->item_count, game->player_pos) == FALSE)
		return (error(EXIT_FAILURE, "Invalid Map"));
	if (is_valid_path(game) == FALSE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	is_rectangle(char **map, int map_size[])
{
	int	i;
	int	j;

	map_size[WIDTH] = 0; // TODO : 해야 할까?
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j]) // TODO : 한 줄로 안 되겠지?
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
	int i;
	int j;

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

static int	is_valid_component(char **map, int *item_count, int player_pos[])
{
	int	cep_count[3];
	int index[2];

	ft_memset(cep_count, 0, sizeof(cep_count));
	index[Y] = 0;
	while (map[index[Y]])
	{
		index[X] = 0;
		while (map[index[Y]][index[X]])
		{
			if (check_compoenent(map[index[Y]][index[X]], cep_count) == FALSE)
				return (FALSE);
			if (map[index[Y]][index[X]] == PLAYER)
			{
				player_pos[Y] = index[Y];
				player_pos[X] = index[X];
			}
			index[X]++;
		}
		index[Y]++;
	}
	if (cep_count[0] < 1 || cep_count[1] != 1 || cep_count[2] != 1)
		return (FALSE);
	*item_count = cep_count[0];
	return (TRUE);
}
