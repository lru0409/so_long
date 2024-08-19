/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:14:18 by rolee             #+#    #+#             */
/*   Updated: 2024/08/19 12:32:33 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	render_map(t_game *game);

void	render_square(t_game *game, void *image, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

void	render(t_game *game)
{
	render_move_count(game);
	render_map(game);
	render_player(game);
}

void	render_move_count(t_game *game)
{
	int		i;
	char	*move_count;

	i = 0;
	while (i < game->map_size[W])
		render_square(game, game->images->empty, 0, i++);
	move_count = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->win, 20, 37, 0x000000, "MOVE COUNT ");
	mlx_string_put(game->mlx, game->win, 120, 37, 0x000000, move_count);
	free(move_count);
}

static void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_size[H])
	{
		x = 0;
		while (x < game->map_size[W])
		{
			render_square(game, game->images->empty, y + 1, x);
			if (game->map[y][x] == WALL)
				render_square(game, game->images->wall, y + 1, x);
			if (game->map[y][x] == ITEM)
				render_square(game, game->images->item, y + 1, x);
			if (game->map[y][x] == EXIT)
				render_square(game, game->images->exit, y + 1, x);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	void	*image;
	int		dir;
	int		count;

	dir = game->player[DIR];
	count = game->move_count % 4;
	image = game->images->player[dir][count];
	render_square(game, image, game->player[Y] + 1, game->player[X]);
}
