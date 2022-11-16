/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:46:23 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/16 16:00:06 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isfloat(char c)
{
	if (ft_isalnum(c) || c != '.')
		return (0);
	return (1);
}
double	ft_atof(char *str)
{
	int		i;
	int		pos;
	double	j;
	double	ret;

	i = 0;
	j = 0.1;
	ret = 0;
	pos = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		pos = -1;
	}
	while (ft_isdigit(str[i]))
		ret *= 10 + str[i++] - '0';
	if (str[i] && str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		ret += str[i] * j;
		j *= 0.1;
	}
	return (ret * pos);
}