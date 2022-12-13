/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:04:49 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:00:05 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	light_parameter(char *line, t_minirt *minirt)
{
	int		i;
	t_light	*light;

	i = 0;
	light = minirt->light;
	if (light_check_line(line, i))
		msg_free_line_exit(minirt, line, ERR_CONFORM_L);
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	light->position = get_vector(line, i, minirt);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	light->intensity = ft_atof(get_double(line, i, minirt));
	if (range_double(light->intensity, 0, 1))
		msg_free_line_exit(minirt, line, ERR_INTENSITY_L);
}

int	light_check_line(char *line, int i)
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
	i = check_eof(line, i);
	if (!i)
		return (1);
	return (0);
}
