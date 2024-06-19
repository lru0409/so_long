/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:32:52 by rolee             #+#    #+#             */
/*   Updated: 2024/06/19 10:55:17 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

# define EMPTY_PATH "./textures/empty.xpm"
# define WALL_PATH "./textures/wall.xpm"
# define ITEM_PATH "./textures/item.xpm"
# define EXIT_PATH "./textures/exit.xpm"
# define PLAYER_PATH "./textures/player_down_0.xpm"

# define EMPTY '0'
# define WALL '1'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define HEIGHT 0
# define WIDTH 1
# define Y 0
# define X 1

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define CLOSE_BUTTON 17

typedef struct s_images
{
	void	*empty;
	void	*wall;
	void	*item;
	void	*exit;
	void	*player;
}	t_images;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_images	*images;
	char		**map;
	int			map_size[2];
	int			total_item_count;
	int			current_item_count;
	int			player[2];
	int			dir[2][4];
	int			move_count;
}	t_game;

typedef struct s_path
{
	char	**map;
	int		**visited;
	int		exit_count;
	int		item_count;
}	t_path;

// util
int		error(int ret, char *message);
int		end(int ret, t_game *game);

// set_game_data
int		set_game_data(t_game *game, char *argv[]);

// check_map
int		is_valid_map(t_game *game);
int		is_valid_path(t_game *game);

// render
void	render_sqaure(t_game *game, void *image, int y, int x);
void	render_map(t_game *game);

// manage_evnet
int		exit_game(t_game *game);
int		press_key(int keycode, t_game *game);

#endif