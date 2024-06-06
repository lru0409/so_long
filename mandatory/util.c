/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:11:39 by rolee             #+#    #+#             */
/*   Updated: 2024/06/06 20:13:20 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(int ret, char *message)
{
	ft_putendl_fd("ERROR", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (ret);
}
