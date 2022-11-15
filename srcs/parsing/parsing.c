/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/15 13:59:02 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parsing(int fd, int ac, char **av, t_objects **obj)
{
	if (check_args(ac, av))
		return ;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	get_file(fd, obj);
}

void	get_file(int fd, t_objects **obj)
{
	char	*line;
	
	line = get_next_line(fd);
	get_line_parameter(line, obj);
}

