/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameter2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:46:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:17:06 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	get_vector(char *line, int i, t_minirt *minirt)
{
	t_vect	vect;

	vect.x = ft_atof(get_x(line, i, minirt));
	vect.y = ft_atof(get_y(line, i, minirt));
	vect.z = ft_atof(get_z(line, i, minirt));
	return (vect);
}

char	*get_x(char *line, int i, t_minirt *minirt)
{
	int		j;
	char	*x;

	j = 0;
	while (line[i] && line[i] != ',')
	{
		i++;
		j++;
	}
	x = malloc(j + 1);
	if (!x)
	{
		free(line);
		msg_free_exit(minirt, ERR_MALLOC);
	}
	i -= j;
	j = 0;
	while (line[i] && line[i] != ',')
		x[j++] = line[i++];
	x[j++] = 0;
	return (x);
}

char	*get_y(char *line, int i, t_minirt *minirt)
{
	int		j;
	char	*y;

	j = 0;
	while (line[i] != ',')
		i++;
	i++;
	while (line[i] && line[i] != ',')
	{
		i++;
		j++;
	}
	y = malloc(j + 1);
	if (!y)
	{
		free(line);
		msg_free_exit(minirt, ERR_MALLOC);
	}
	i -= j;
	j = 0;
	while (line[i] && line[i] != ',')
		y[j++] = line[i++];
	y[j++] = 0;
	return (y);
}

char	*get_z(char *line, int i, t_minirt *minirt)
{
	int		j;
	char	*z;

	while (line[i++] != ',')
		;
	while (line[i++] != ',')
		;
	j = 0;
	while (line[i] && line[i] != ' ')
	{
		i++;
		j++;
	}
	z = malloc(j + 1);
	if (!z)
	{
		free(line);
		msg_free_exit(minirt, ERR_MALLOC);
	}
	i -= j;
	j = 0;
	while (line[i] && line[i] != ' ')
		z[j++] = line[i++];
	z[j++] = 0;
	return (z);
}
