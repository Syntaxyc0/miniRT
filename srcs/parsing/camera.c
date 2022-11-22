/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:18 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/22 18:16:24 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_parameter(char *line, t_minirt *minirt)
{
	int	i;
	t_camera *camera;

	i = 0;
	camera = minirt->camera;
	if (camera_check_line(line))
		msg_free_exit(minirt, ERR_CONFORM);
	while (ft_isalpha(line[i]))
		i++;
	camera->angle = get_vector(line, i, minirt);
	
}