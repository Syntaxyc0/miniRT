/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:46:23 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:23:05 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isdouble(char c)
{
	if (ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}

double	ft_atof(char *str)
{
	int		i;
	int		pos;
	double	j;
	double	ret;

	i = 0;
	j = 1;
	ret = 0;
	pos = 1;
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
		ret = ret * 10 + (str[i++] - '0');
		j *= 10;
	}
	free(str);
	return ((ret / j) * pos);
}

unsigned int	ft_atoui(char *str)
{
	int				i;
	unsigned int	ret;

	ret = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + (str[i++] - '0');
	free(str);
	return (ret);
}

int	str_big(char *str1, char *str2)
{
	if (ft_strlen(str1) > ft_strlen(str2))
		return (ft_strlen(str1));
	else
		return (ft_strlen(str2));
}

t_objects	*last_obj(t_objects *obj)
{
	while (obj->next)
		obj = obj->next;
	return (obj);
}
