/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_spe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:11:37 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:02:25 by ggobert          ###   ########.fr       */
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
	return (sphere);
}
