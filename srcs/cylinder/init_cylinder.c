/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:40 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:06:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*init_cylinder(t_vect point, t_vect normal, float diameter, float height, t_color color)
{
	t_cylinder	*ret;

	ret = malloc(sizeof(t_cylinder));
	if (!ret)
		return (NULL);
	ret->point = point;
	ret->normal = normal;
	ret->diameter = diameter;
	ret->height = height;
	ret->color = color;
	return (ret);
}