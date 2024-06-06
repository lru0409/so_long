/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:32:52 by rolee             #+#    #+#             */
/*   Updated: 2024/06/06 12:49:12 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"

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
	char	**map;
	void	*mlx;
	void	*win;
}	t_game;

#endif