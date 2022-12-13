/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:53:03 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:21:26 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_vector(char *line, int i)
{
	int	count;

	count = 0;
	while (count++ < 3)
	{
		i = check_double(line, i);
		if (!i)
			return (0);
		if (count != 3)
			if (line[i++] != ',')
				return (0);
	}
	return (i);
}

int	check_color(char *line, int i)
{
	int	count;

	count = 0;
	while (count++ < 3)
	{
		if (!ft_isdigit(line[i]))
			return (0);
		while (ft_isdigit(line[i]))
			i++;
		if (count != 3)
			if (line[i++] != ',')
				return (0);
	}
	return (i);
}

int	check_space(char *line, int i)
{
	if (line[i] != ' ')
		return (0);
	while (line[i] == ' ')
		i++;
	return (i);
}

int	check_double(char *line, int i)
{
	if (!ft_isdigit(line[i]) && line[i] != '-')
		return (0);
	if (line[i] == '-')
		i++;
	if (!ft_isdigit(line[i]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (!line[i] || line[i] == ' ' || line[i] == ',' || line[i] == '\n')
		return (i);
	if (line[i] != '.')
		return (0);
	i++;
	if (!ft_isdigit(line[i]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	return (i);
}

int	check_digit(char *line, int i)
{
	if (!ft_isdigit(line[i]) || line[i] == '-')
		return (0);
	while (ft_isdigit(line[++i]))
		;
	return (i);
}
