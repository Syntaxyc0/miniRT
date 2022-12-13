/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:19:33 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:10:50 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ambiant_parameter(char *line, t_minirt *minirt)
{
	int			i;
	t_ambiant	*ambiant;

	i = 0;
	ambiant = minirt->ambiant;
	if (ambiant_check_line(line, i))
		msg_free_line_exit(minirt, line, ERR_CONFORM_A);
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	ambiant->intensity = ft_atof(get_double(line, i, minirt));
	if (range_double(ambiant->intensity, 0, 1))
		msg_free_line_exit(minirt, line, ERR_INTENSITY_A);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	ambiant->color = get_colors(line, i, minirt);
}

int	ambiant_check_line(char *line, int i)
{
	while (ft_isalpha(line[i]))
		i++;
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
