/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:40:01 by rolee             #+#    #+#             */
/*   Updated: 2024/06/20 21:43:53 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define PLAYER_UP_PATH "./textures/player_up_"
# define PLAYER_DOWN_PATH "./textures/player_down_"
# define PLAYER_LEFT_PATH "./textures/player_left_"
# define PLAYER_RIGHT_PATH "./textures/player_right_"

# define EMPTY '0'
# define WALL '1'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define H 0
# define W 1
# define Y 0
# define X 1
# define DIR 2

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
	void	*player[4][4];
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
	int			player[3];
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
int		set_map(char *filename, t_game *game);
int		set_images(t_game *game);
void	clear_game_data(t_game *game);

// check_map
int		is_valid_map(t_game *game);
int		is_valid_path(t_game *game);

// render
void	render_square(t_game *game, void *image, int y, int x);
void	render(t_game *game);
void	render_player(t_game *game);

// manage_event
int		exit_game(t_game *game);
int		press_key(int keycode, t_game *game);

#endif