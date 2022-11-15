/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/15 12:49:15 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parsing(int fd, int ac, char **av)
{
	if (check_args(ac, av))
		return ;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	get_parameter(fd);
}

void	get_parameter(int fd, )