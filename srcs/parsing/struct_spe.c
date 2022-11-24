/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_spe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:11:37 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/16 13:39:25 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambiant	*new_ambiant(void)
{
	t_ambiant	*ambiant;

	ambiant = malloc(sizeof(t_ambiant));
	if (!ambiant)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	ambiant->intensity = 0;
	ambiant->color = malloc(sizeof(t_color));
	if (!ambiant->color)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	ambiant->color.red = 0;
	ambiant->color.blue = 0;
	ambiant->color.green = 0;
	return (ambiant);
}

t_camera	*new_camera(void)
{
	t_camera	*camera;
	
	camera = malloc(sizeof(t_camera));
	if (!camera)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	camera->position = malloc(sizeof(t_vect));
	if (!camera->position)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	camera->position.x = 0;
	camera->position.y = 0;
	camera->position.z = 0;
	camera->orientation = malloc(sizeof(t_vect));
	if (!camera->orientation)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	camera->orientation.x = 0;
	camera->orientation.y = 0;
	camera->orientation.z = 0;
	camera->angle = 0;
	return (camera);
}

t_light	*new_light(void)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	light->intensity = 0;
	light->position = malloc(sizeof(t_vect));
	if (!light->position)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	light->position.x = 0;
	light->position.y = 0;
	light->position.z = 0;
	return (light);
}

t_sphere	*new_sphere(void)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	sphere->center = malloc(sizeof(t_vect));
	if (!sphere->center)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	sphere->center.x = 0;
	sphere->center.y = 0;
	sphere->center.z = 0;
	sphere->radius = 0;
	sphere->color = malloc(sizeof(t_color));
	if (!sphere->color)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	sphere->color.red = 0;
	sphere->color.blue = 0;
	sphere->color.green = 0;
	return (sphere);
}
