/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:46:23 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/21 14:38:21 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isfloat(char c)
{
	if (ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}

float	ft_atof(char *str)
{
	int		i;
	int		pos;
	float	j;
	float	ret;

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
		ret = ret * 10 + (str[i++] - '0');
	if (str[i] && str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		ret += (str[i++] - '0') * j;
		j *= 0.1;
	}
	return (ret * pos);
}

unsigned int ft_atoui(char *str)
{
	unsigned int	ret;

	ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + (*str++ - '0');
	return (ret);
}
