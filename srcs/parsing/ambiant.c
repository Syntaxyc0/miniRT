/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:19:33 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/16 15:49:00 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	ambiant_parameter(char *line, int type, t_objects *obj, t_objects **objects)
{
	int	i;

	i = 0;
	while (line[i] == 'A')
		i++;
	while (line[i] == ' ')
		i++;
	get_intensity(line, i, obj, objects);
}

void	get_intensity(char *line, int i, t_objects *obj, t_objects **objects)
{
	char	*intensity;

	j = 0;
	while (line[i] != ' ')
		i++;
		j++;
	intensity = malloc(j +1);
	if (!intensity)
		msg_free_exit(objects, ERR_MALLOC);
	i -= j;
	j = 0;
	while (line[i] && ft_isfloat(line[i]))
		intensity[j++] = line[i++];
	intensity[++j] = 0;
		
}