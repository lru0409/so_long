/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:32:35 by rolee             #+#    #+#             */
/*   Updated: 2024/06/06 12:56:37 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg(int argc, char *argv[])
{
	char	*map_file;
	int		len;

	if (argc != 2)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd("Invalid Argument", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	map_file = argv[1];
	len = ft_strlen(map_file);
	if (ft_strncmp(map_file + len - 4, ".ber", 4) != 0)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd("Invalid File Extension", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	if (check_arg(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}