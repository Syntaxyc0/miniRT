/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_spe2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:38:59 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/16 13:43:55 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*new_plane(void)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	plane->point = malloc(sizeof(t_vect));
	if (!plane->point)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	plane->point.x = 0;
	plane->point.y = 0;
	plane->point.z = 0;
	plane->normal = malloc(sizeof(t_vect));
	if (!plane->normal)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	plane->normal.x = 0;
	plane->normal.y = 0;
	plane->normal.z = 0;
	plane->color = malloc(sizeof(t_color));
	if (!plane->color)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	return (plane);
}

t_cylinder	*new_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	cylinder->point = malloc(sizeof(t_vect));
	if (!cylinder->point)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	cylinder->point.x = 0;
	cylinder->point.y = 0;
	cylinder->point.z = 0;
	cylinder->normal = malloc(sizeof(t_vect));
	if (!cylinder->normal)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	cylinder->normal.x = 0;
	cylinder->normal.y = 0;
	cylinder->normal.z = 0;
	cylinder->diameter = 0;
	cylinder->height = 0;
	cylinder->color = malloc(sizeof(t_color));
	if (!cylinder->color)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	cylinder->color.red = 0;
	cylinder->color.blue = 0;
	cylinder->color.green = 0;
	return (cylinder);
}
