/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:08:16 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:14:13 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	plane_parameter(char *line, t_minirt *minirt, t_objects *obj)
{
	int		i;
	t_plane	*plane;

	i = 0;
	plane = (t_plane *)obj->object;
	if (plane_check_line(line, i))
		msg_free_line_exit(minirt, line, ERR_CONFORM_PL);
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	plane->point = get_vector(line, i, minirt);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	plane->normal = get_vector(line, i, minirt);
	if (range_vector(plane->normal, -1, 1))
		msg_free_line_exit(minirt, line, ERR_ORIENT_PL);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	plane->color = get_colors(line, i, minirt);
}

int	plane_check_line(char *line, int i)
{
	while (ft_isalpha(line[i]))
		i++;
	i = check_space(line, i);
	if (!i)
		return (1);
	i = check_vector(line, i);
	if (!i)
		return (1);
	i = check_space(line, i);
	if (!i)
		return (1);
	i = check_vector(line, i);
	if (!i)
		return (1);
	i = check_space(line, i);
	if (!i)
		return (1);
	i = check_color(line, i);
	if (!i)
		return (1);
	i = check_eof(line, i);
	if (!i)
		return (1);
	return (0);
}
