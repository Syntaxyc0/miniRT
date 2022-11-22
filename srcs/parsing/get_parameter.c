/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:18:30 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/22 15:23:37 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*get_intensity(char *line, int i, t_minirt *minirt)
{
	int		j;
	char	*intensity;

	j = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && ft_isfloat(line[i]))
	{
		i++;
		j++;
	}
	intensity = malloc(j + 1);
	if (!intensity)
		msg_free_exit(minirt, ERR_MALLOC);
	i -= j;
	j = 0;
	while (line[i] && ft_isfloat(line[i]))
		intensity[j++] = line[i++];
	intensity[j] = 0;
	return (intensity);
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
	int 	j;
	char	*red;

	j = 0;
	while (line[i] && line[i] != ',')
	{
		i++;
		j++;
	}
	red = malloc(j + 1);
	if (!red)
		msg_free_exit(minirt, ERR_MALLOC);
	i -= j;
	j = 0;
	while (line[i] && line[i] != ',')
		red[j++] = line[i++];
	red[j++] = 0;
	return (red);
}

char	*get_green(char *line, int i, t_minirt *minirt)
{
	int 	j;
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
		msg_free_exit(minirt, ERR_MALLOC);
	i -= j;
	j = 0;
	while (line[i] && line[i] != ',')
		green[j++] = line[i++];
	green[j++] = 0;
	return (green);
}

char	*get_blue(char *line, int i, t_minirt *minirt)
{
	int 	j;
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
