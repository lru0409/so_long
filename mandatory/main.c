/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:32:35 by rolee             #+#    #+#             */
/*   Updated: 2024/06/17 11:16:20 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg(int argc, char *argv[])
{
	char	*map_file;
	int		len;

	if (argc != 2)
		return (error(EXIT_FAILURE, "Invalid Argument"));
	map_file = argv[1];
	len = ft_strlen(map_file);
	if (ft_strncmp(map_file + len - 4, ".ber", 4) != 0)
		return (error(EXIT_FAILURE, "Invalid File Extension"));
	return (EXIT_SUCCESS);
}

int	end(int ret, t_game *game)
{
	clear_game_data(game);
	return (ret);
}

t_game	*init_game_data()
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->images = NULL;
	game->map = NULL;
	game->map_size[WIDTH] = 0;
	game->map_size[HEIGHT] = 0;
	game->total_item_count = 0;
	game->current_item_count = 0;
	ft_memset(game->player, 0, sizeof(game->player));
	ft_memset(game->dir, 0, sizeof(game->dir));
	game->dir[Y][UP] = -1;
	game->dir[Y][DOWN] = 1;
	game->dir[X][LEFT] = -1;
	game->dir[X][RIGHT] = 1;
	game->move_count =  0;
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (check_arg(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game = init_game_data();
	if (!game)
		return (EXIT_FAILURE);
	if (set_game_data(game, argv) == EXIT_FAILURE)
		return (end(EXIT_FAILURE, game));
	if (is_valid_map(game) == FALSE)
		return (end(EXIT_FAILURE, game));

	game->win = mlx_new_window(game->mlx, \
		game->map_size[WIDTH] * 64, game->map_size[HEIGHT] * 64, "so_long");
	render_map(game);
	mlx_key_hook(game->win, &press_key, game);
	mlx_hook(game->win, CLOSE_BUTTON, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
