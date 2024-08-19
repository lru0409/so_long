/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:54:07 by rolee             #+#    #+#             */
/*   Updated: 2024/08/19 12:31:47 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*get_file_path(int dir, int count);
static int	set_player_images(t_game *game, int w, int h);

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
	if (set_player_images(game, w, h) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	set_player_images(t_game *game, int w, int h)
{
	int		dir;
	int		count;
	char	*file_path;

	dir = 0;
	while (dir < 4)
	{
		count = 0;
		while (count < 4)
		{
			file_path = get_file_path(dir, count);
			if (!file_path)
				return (EXIT_FAILURE);
			game->images->player[dir][count] = \
				mlx_xpm_file_to_image(game->mlx, file_path, &w, &h);
			free(file_path);
			count++;
		}
		dir++;
	}
	return (EXIT_SUCCESS);
}

static char	*get_file_path(int dir, int count)
{
	char	*temp;
	char	*file_path;

	temp = NULL;
	if (dir == UP)
		temp = ft_strjoin(PLAYER_UP_PATH, ft_itoa(count));
	else if (dir == DOWN)
		temp = ft_strjoin(PLAYER_DOWN_PATH, ft_itoa(count));
	else if (dir == LEFT)
		temp = ft_strjoin(PLAYER_LEFT_PATH, ft_itoa(count));
	else if (dir == RIGHT)
		temp = ft_strjoin(PLAYER_RIGHT_PATH, ft_itoa(count));
	file_path = ft_strjoin(temp, ".xpm");
	free(temp);
	return (file_path);
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
