/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:11:39 by rolee             #+#    #+#             */
/*   Updated: 2024/06/19 10:55:45 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_game_data(t_game *game);

int	error(int ret, char *message)
{
	ft_putendl_fd("ERROR", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (ret);
}

int	end(int ret, t_game *game)
{
	clear_game_data(game);
	return (ret);
}

void	clear_game_data(t_game *game)
{
	int	index;

	if (game->images)
		free(game->images);
	if (game->map)
	{
		index = 0;
		while (index < game->map_size[HEIGHT])
			free(game->map[index++]);
		free(game->map);
	}
	free(game);
}
