/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:35:06 by ggobert           #+#    #+#             */
/*   Updated: 2022/12/07 11:05:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt	*init_minirt(void)
{
	t_minirt	*minirt;

	minirt = malloc(sizeof(t_minirt));
	if (!minirt)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	minirt->ambiant = 0;
	minirt->camera = 0;
	minirt->light = 0;
	minirt->objects = 0;
	minirt->img = 0;
	minirt->id = 0;
	return (minirt);
}
