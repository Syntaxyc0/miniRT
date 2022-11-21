/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:19:33 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/21 14:38:59 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	ambiant_parameter(char *line, t_objects *obj, t_objects **objects)
{
	int	i;
	t_ambiant *ambiant;

	i = 0;
	ambiant = obj->object;
	while (line[i] == 'A')
		i++;
	while (line[i] == ' ')
		i++;
	ambiant->intensity = ft_atof(get_intensity(line, i, objects));
	if (ambiant->intensity < 0 || ambiant->intensity > 1)
		msg_free_exit(objects, ERR_INTENS);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	ambiant->color = get_colors(line, i, objects);
}
