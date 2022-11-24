/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:31:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 11:45:55 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cylinder_parameter(char *line, t_minirt *minirt, t_objects *obj)
{
	int	i;
	t_cylinder *cylinder;

	i = 0;
	cylinder = (t_cylinder*)obj->object;
	if (cylinder_check_line(line, i))
		msg_free_line_exit(minirt, line, ERR_CONFORM_CY);
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	cylinder->point = get_vector(line, i, minirt);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	cylinder->normal = get_vector(line, i, minirt);
	if (range_vector(cylinder->normal, -1, 1))
		msg_free_line_exit(minirt, line, ERR_ORIENT_CY);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	cylinder->height = ft_atof(get_float(line, i, minirt));
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	cylinder->diameter = ft_atof(get_float(line, i, minirt));
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	cylinder->color = get_colors(line, i, minirt);
}

int	cylinder_check_line(char *line, int i)
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
	i = check_float(line, i);
	if (!i)
		return (1);
	i = check_space(line, i);
	if (!i)
		return (1);
	i = check_float(line, i);
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