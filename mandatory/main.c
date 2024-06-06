/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:32:35 by rolee             #+#    #+#             */
/*   Updated: 2024/06/06 20:35:38 by rolee            ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	if (check_arg(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (set_game_data(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE); // TODO 메모리 해제
	

	return (EXIT_SUCCESS);
}