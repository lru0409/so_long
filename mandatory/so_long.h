/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:32:52 by rolee             #+#    #+#             */
/*   Updated: 2024/06/06 21:04:50 by rolee            ###   ########.fr       */
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
# define PLAYER_PATH "./textures/player.xpm"

# define EMPTY '0'
# define WALL '1'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'


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
	char		**map;
	int			item_count;
	void		*mlx;
	t_images	*images;
	void		*win;
}	t_game;

// util
int		error(int ret, char *message);

// set_game_data
t_game	*set_game_data(char *argv);

#endif