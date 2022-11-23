/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/23 16:07:35 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parsing(int fd, int ac, char **av, t_minirt *minirt)
{
	if (check_args(ac, av))
		return ;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("minirt");
		exit(EXIT_FAILURE);
	}
	get_file(fd, minirt);
}

void	get_file(int fd, t_minirt *minirt)
{
	char	*line;
	
	line = get_next_line(fd);
	while (line)
	{
		if (!(*line == '\n'))
			get_line_parameter(line, minirt);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}
