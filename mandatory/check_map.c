/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:35:52 by rolee             #+#    #+#             */
/*   Updated: 2024/06/06 21:07:09 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	int	i;
	int	j;
	int	wid;

	wid = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j]) // TODO : 한 줄로 안 되겠지?
			j++;
		if (wid == 0)
			wid = j;
		else if (wid != j)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_surrounded_wall(char **map)
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

int	is_valid_component(char **map, int *item_count)
{
	int	cep_count[3];
	int	i;
	int j;

	ft_memset(cep_count, 0, sizeof(cep_count));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != EMPTY && map[i][j] != WALL && map[i][j] != ITEM && \
				map[i][j] != EXIT && map[i][j] != PLAYER)
				return (FALSE);
			if (map[i][j] == ITEM)
				cep_count[0]++;
			else if (map[i][j] == EXIT)
				cep_count[1]++;
			else if (map[i][j] == PLAYER)
				cep_count[2]++;
			j++;
		}
		i++;
	}
	if (cep_count[0] < 1 || cep_count[1] != 1 || cep_count[2] != 1)
		return (FALSE);
	*item_count = cep_count[0];
	return (TRUE);
}

int	is_invalid_map(t_game *game) // TODO : wid, height 등 저장해야 할까?
{
	if (is_rectangle(game->map) == FALSE)
		return (error(EXIT_FAILURE, "Invalid Map"));
	if (is_surrounded_wall(game->map) == FALSE)
		return (error(EXIT_FAILURE, "Invalid Map"));
	if (is_valid_component(game->map, &game->item_count) == FALSE)
		return (error(EXIT_FAILURE, "Invalid Map"));
	// TODO : is_valid_path
	return (EXIT_SUCCESS);
}
