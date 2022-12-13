/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:18 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:12:17 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_parameter(char *line, t_minirt *minirt)
{
	int			i;
	t_camera	*camera;

	i = 0;
	camera = minirt->camera;
	if (camera_check_line(line, i))
		msg_free_exit(minirt, ERR_CONFORM_C);
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	camera->position = get_vector(line, i, minirt);
	i = next_value(line, i);
	camera->orientation = get_vector(line, i, minirt);
	if (range_vector(camera->orientation, -1, 1))
		msg_free_line_exit(minirt, line, ERR_ORIENT_C);
	i = next_value(line, i);
	camera->angle = ft_atof(get_double(line, i, minirt));
	if (range_double(camera->angle, 0, 180))
		msg_free_line_exit(minirt, line, ERR_FOV_C);
}

int	camera_check_line(char *line, int i)
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
	i = check_digit(line, i);
	if (!i)
		return (1);
	i = check_eof(line, i);
	if (!i)
		return (1);
	return (0);
}
