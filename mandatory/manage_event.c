/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:16:59 by rolee             #+#    #+#             */
/*   Updated: 2024/06/19 10:56:10 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int dir_index);
static void	game_clear(t_game *game);

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(end(EXIT_SUCCESS, game));
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player(game, UP);
	else if (keycode == KEY_A)
		move_player(game, LEFT);
	else if (keycode == KEY_S)
		move_player(game, DOWN);
	else if (keycode == KEY_D)
		move_player(game, RIGHT);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

static void	move_player(t_game *game, int dir_index)
{
	int	ny;
	int	nx;

	ny = game->player[Y] + game->dir[Y][dir_index];
	nx = game->player[X] + game->dir[X][dir_index];
	if (game->map[ny][nx] == 'E' && \
		game->current_item_count == game->total_item_count)
		game_clear(game);
	if (game->map[ny][nx] == WALL || game->map[ny][nx] == EXIT)
		return ;
	if (game->map[ny][nx] == ITEM)
	{
		game->current_item_count++;
		game->map[ny][nx] = EMPTY;
		render_sqaure(game, game->images->empty, ny, nx);
	}
	render_sqaure(game, game->images->empty, game->player[Y], game->player[X]);
	render_sqaure(game, game->images->player, ny, nx);
	game->player[Y] = ny;
	game->player[X] = nx;
	game->move_count++;
	ft_putnbr_fd(game->move_count, STDOUT_FILENO);
	ft_putendl_fd(" moves", STDOUT_FILENO);
}

static void	game_clear(t_game *game)
{
	ft_putstr_fd("Clear game in ", STDOUT_FILENO);
	ft_putnbr_fd(game->move_count, STDOUT_FILENO);
	ft_putendl_fd(" moves!", STDOUT_FILENO);
	exit_game(game);
}
