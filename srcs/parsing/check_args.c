/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:43:38 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/21 13:37:37 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int check_args(int ac, char **av)
{
	if (ac != 2)
	{
		print_error(ERR_NBARGS);
		exit(EXIT_FAILURE);
	}
	if (!is_rt(av[1]))
	{
		print_error(ERR_TYPEARG);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	is_rt(char *str)
{
	int	i;

	i = ft_strlen(str);
	i -= 3;
	if (ft_strncmp(str + i, ".rt", str_big(str + i, ".rt")))
		return (0);
	return (1);
}

int	str_big(char *str1, char *str2)
{
	if (ft_strlen(str1) > ft_strlen(str2))
		return (ft_strlen(str1));
	else
		return (ft_strlen(str2));
}
