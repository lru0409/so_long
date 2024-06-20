/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:51:36 by rolee             #+#    #+#             */
/*   Updated: 2024/06/20 20:42:23 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sqaure(t_game *game, void *image, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_size[H])
	{
		x = 0;
		while (x < game->map_size[W])
		{
			render_sqaure(game, game->images->empty, y, x);
			if (game->map[y][x] == WALL)
				render_sqaure(game, game->images->wall, y, x);
			if (game->map[y][x] == ITEM)
				render_sqaure(game, game->images->item, y, x);
			if (game->map[y][x] == EXIT)
				render_sqaure(game, game->images->exit, y, x);
			x++;
		}
		y++;
	}
	render_sqaure(game, game->images->player, game->player[Y], game->player[X]);
}
