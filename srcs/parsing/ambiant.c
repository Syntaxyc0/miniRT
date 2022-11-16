/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:19:33 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/16 14:23:51 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	ambiant_parameter(char *line, int type, t_objects *obj)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (!ft_isalnum(line[i]))
			while (ft_isalpha(line[i]));
				i++;
		else
		{
			print_error(ERR_ID);
			exi
		}
		while (line[i] == ' ')
			i++;
		if (line)
	}
}