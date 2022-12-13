/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:18:30 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:13:13 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*get_double(char *line, int i, t_minirt *minirt)
{
	int		j;
	char	*double_value;

	j = 0;
	while ((line[i] && ft_isdouble(line[i])) || (line[i] && line[i] == '-'))
	{
		i++;
		j++;
	}
	double_value = malloc(j + 1);
	if (!double_value)
		msg_free_exit(minirt, ERR_MALLOC);
	i -= j;
	j = 0;
	while ((line[i] && ft_isdouble(line[i])) || (line[i] && line[i] == '-'))
		double_value[j++] = line[i++];
	double_value[j] = 0;
	return (double_value);
}

t_color	get_colors(char *line, int i, t_minirt *minirt)
{
	t_color	color;

	color.red = ft_atoui(get_red(line, i, minirt));
	if (color.red > 255)
		msg_free_exit(minirt, ERR_COLOR);
	color.green = ft_atoui(get_green(line, i, minirt));
	if (color.green > 255)
		msg_free_exit(minirt, ERR_COLOR);
	color.blue = ft_atoui(get_blue(line, i, minirt));
	if (color.blue > 255)
		msg_free_exit(minirt, ERR_COLOR);
	return (color);
}

char	*get_red(char *line, int i, t_minirt *minirt)
{
	int		j;
	char	*red;

	j = 0;
	while (line[i] && line[i] != ',')
	{
		i++;
		j++;
	}
	red = malloc(j + 1);
	if (!red)
	{
		free(line);
		msg_free_exit(minirt, ERR_MALLOC);
	}
	i -= j;
	j = 0;
	while (line[i] && line[i] != ',')
		red[j++] = line[i++];
	red[j++] = 0;
	return (red);
}

char	*get_green(char *line, int i, t_minirt *minirt)
{
	int		j;
	char	*green;

	j = 0;
	while (line[i] && line[i] != ',')
		i++;
	i++;
	while (line[i] && line[i] != ',')
	{
		i++;
		j++;
	}
	green = malloc(j + 1);
	if (!green)
	{
		free(line);
		msg_free_exit(minirt, ERR_MALLOC);
	}
	i -= j;
	j = 0;
	while (line[i] && line[i] != ',')
		green[j++] = line[i++];
	green[j++] = 0;
	return (green);
}

char	*get_blue(char *line, int i, t_minirt *minirt)
{
	int		j;
	char	*blue;

	j = 0;
	while (line[i] && line[i] != ',')
		i++;
	i++;
	while (line[i] && line[i] != ',')
		i++;
	i++;
	while (line[i] && line[i] != ' ')
	{
		i++;
		j++;
	}
	blue = malloc(j + 1);
	if (!blue)
		msg_free_exit(minirt, ERR_MALLOC);
	i -= j;
	j = 0;
	while (line[i] && line[i] != ' ')
		blue[j++] = line[i++];
	blue[j++] = 0;
	return (blue);
}
