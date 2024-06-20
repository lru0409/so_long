/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:09:26 by rolee             #+#    #+#             */
/*   Updated: 2024/06/20 21:09:50 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int			set_map(char *filename, t_game *game);
static char	*get_map_str(int fd);
static int	is_valid_newline(char *map_str);

int	set_map(char *filename, t_game *game)
{
	int		fd;
	char	*map_str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error(EXIT_FAILURE, "Invalid File"));
	map_str = get_map_str(fd);
	close(fd);
	if (!map_str)
		return (EXIT_FAILURE);
	if (map_str[0] == '\0' || is_valid_newline(map_str) == FALSE)
	{
		free(map_str);
		return (error(EXIT_FAILURE, "Invalid Map"));
	}
	game->map = ft_split(map_str, '\n');
	free(map_str);
	if (!game->map || is_valid_map(game) == FALSE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static char	*get_map_str(int fd)
{
	char	*line;
	char	*map_str;
	char	*temp;

	map_str = ft_strdup("");
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = map_str;
		map_str = ft_strjoin(map_str, line);
		free(line);
		free(temp);
		if (!map_str)
			return (NULL);
	}
	return (map_str);
}

static int	is_valid_newline(char *map_str)
{
	int	index;
	int	nl_flag;

	if (map_str[0] == '\n')
		return (FALSE);
	if (map_str[ft_strlen(map_str) - 1] == '\n')
		return (FALSE);
	index = 0;
	nl_flag = FALSE;
	while (map_str[index])
	{
		if (map_str[index] == '\n' && nl_flag)
			return (FALSE);
		else if (map_str[index] == '\n')
			nl_flag = TRUE;
		else
			nl_flag = FALSE;
		index++;
	}
	return (TRUE);
}
