/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:52:44 by rolee             #+#    #+#             */
/*   Updated: 2024/06/20 21:04:56 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_images(t_game *game)
{
	int	w;
	int	h;

	game->images = (t_images *)malloc(sizeof(t_images));
	if (!game->images)
		return (EXIT_FAILURE);
	game->images->empty = mlx_xpm_file_to_image(game->mlx, EMPTY_PATH, &w, &h);
	game->images->wall = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &w, &h);
	game->images->item = mlx_xpm_file_to_image(game->mlx, ITEM_PATH, &w, &h);
	game->images->exit = mlx_xpm_file_to_image(game->mlx, EXIT_PATH, &w, &h);
	game->images->player = mlx_xpm_file_to_image(game->mlx, \
													PLAYER_PATH, &w, &h);
	return (EXIT_SUCCESS);
}

void	clear_game_data(t_game *game)
{
	int	index;

	if (game->images)
		free(game->images);
	if (game->map)
	{
		index = 0;
		while (game->map[index])
			free(game->map[index++]);
		free(game->map);
	}
	free(game);
}
