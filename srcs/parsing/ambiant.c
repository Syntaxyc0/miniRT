/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:19:33 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/22 17:45:32 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	ambiant_parameter(char *line, t_minirt *minirt)
{
	int	i;
	t_ambiant *ambiant;

	i = 0;
	ambiant = minirt->ambiant;
	if (ambiant_check_line(line))
		msg_free_exit(minirt, ERR_CONFORM);
	while (ft_isalpha(line[i]))
		i++;
	ambiant->intensity = ft_atof(get_intensity(line, i, minirt));
	if (ambiant->intensity < 0 || ambiant->intensity > 1)
	{
		free(line);
		msg_free_exit(minirt, ERR_INTENS);
	}
	while (line[i] != ' ')
		i++;
	ambiant->color = get_colors(line, i, minirt);
}

int	ambiant_check_line(char *line)
{
	int	i;
	
	i = 0;
	if (line[i++] != 'A')
		return (1);
	if (line[i++] != ' ')
		return (1);
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ')
		if (!ft_isfloat(line[i++]))
			return (1);
	if (line[i++] != ' ')
		return (1);
	while (line[i] && line[i] != ' ' && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]) && line[i] != ',')
			return (1);
		i++;
	}
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}