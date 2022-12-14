/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:01:47 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:20:25 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_obj(int type, t_minirt *minirt, char *line)
{
	t_objects	*obj;

	obj = minirt->objects;
	if (!obj && type > 3)
	{
		obj = new_struct_objects();
		minirt->objects = obj;
	}
	else if (type > 3)
	{
		obj = last_obj(obj);
		obj->next = new_struct_objects();
		obj = obj->next;
	}
	obj_type(minirt, type, line, obj);
}

t_objects	*new_struct_objects(void)
{
	t_objects	*obj;

	obj = malloc(sizeof(t_objects));
	if (!obj)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	obj->type = 0;
	obj->object = 0;
	obj->next = 0;
	return (obj);
}

void	obj_type(t_minirt *minirt, int type, char *line, t_objects *obj)
{
	if (type == 1)
	{
		(void)obj;
		if (minirt->ambiant)
		{
			free(line);
			msg_free_exit(minirt, ERR_double_A);
		}
		minirt->ambiant = (void *)new_ambiant();
		ambiant_parameter(line, minirt);
	}
	if (type == 2)
	{
		(void)obj;
		if (minirt->camera)
		{
			free(line);
			msg_free_exit(minirt, ERR_double_A);
		}
		minirt->camera = (void *)new_camera();
		camera_parameter(line, minirt);
	}
	obj_type2(minirt, type, line, obj);
}

void	obj_type2(t_minirt *minirt, int type, char *line, t_objects *obj)
{
	if (type == 3)
	{
		(void)obj;
		if (minirt->light)
		{
			free(line);
			msg_free_exit(minirt, ERR_double_L);
		}
		minirt->light = (void *)new_light();
		light_parameter(line, minirt);
	}
	if (type == 4)
	{
		obj->type = 4;
		obj->object = (void *)new_sphere();
		sphere_parameter(line, minirt, obj);
	}
	if (type == 5)
	{
		obj->type = 5;
		obj->object = (void *)new_plane();
		plane_parameter(line, minirt, obj);
	}
	obj_type3(minirt, type, line, obj);
}

void	obj_type3(t_minirt *minirt, int type, char *line, t_objects *obj)
{
	if (type == 6)
	{
		obj->type = 6;
		obj->object = (void *)new_cylinder();
		cylinder_parameter(line, minirt, obj);
	}
}
