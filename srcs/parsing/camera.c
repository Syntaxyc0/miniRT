/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:18 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/23 11:10:38 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_parameter(char *line, t_minirt *minirt)
{
	int	i;
	t_camera *camera;

	i = 0;
	camera = minirt->camera;
	if (camera_check_line(line, i))
		msg_free_exit(minirt, ERR_CONFORM_C);
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	camera->angle = get_vector(line, i, minirt);
	while (line[i] == ' ')
		i++;
	camera->orientation = get_vector(line, i, minirt);
	while (line[i] == ' ')
		i++;
	camera->angle = get_float(line, i, minirt);
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

