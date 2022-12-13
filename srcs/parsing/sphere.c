/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:09:52 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:13:42 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sphere_parameter(char *line, t_minirt *minirt, t_objects *obj)
{
	int			i;
	t_sphere	*sphere;

	i = 0;
	sphere = (t_sphere *)obj->object;
	if (sphere_check_line(line, i))
		msg_free_line_exit(minirt, line, ERR_CONFORM_SP);
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	sphere->center = get_vector(line, i, minirt);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	sphere->radius = ft_atof(get_double(line, i, minirt));
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	sphere->color = get_colors(line, i, minirt);
}

int	sphere_check_line(char *line, int i)
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
	i = check_double(line, i);
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
