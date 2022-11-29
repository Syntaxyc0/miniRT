/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:07:00 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:23:18 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_eof(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (i);
}

int	next_value(char *line, int i)
{
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	return (i);
}
