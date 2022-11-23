/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:01:47 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/23 15:51:12 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_obj(int	type, t_minirt *minirt, char *line)
{
	t_objects *obj;

	obj = minirt->objects;
	if (!obj && type > 3)
	{
		obj = malloc(sizeof(t_objects *));
		if (!obj)
			msg_free_exit(minirt, ERR_MALLOC);
		obj = new_struct_objects();
	}
	else if (type > 3)
	{
		obj = last_obj(obj);
		obj->next = new_struct_objects();
	}
	obj_type(minirt, type, line, obj);
}

t_objects	*last_obj(t_objects *obj)
{
	while (obj)
		obj = obj->next;
	return (obj);
}

t_objects	*new_struct_objects(void)
{
	t_objects *obj;

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
			msg_free_exit(minirt, ERR_DOUBLE_A);
		}
		minirt->ambiant = (void*)new_ambiant();
		ambiant_parameter(line, minirt);
	}
	if (type == 2)
	{
		(void)obj;
		if (minirt->camera)
		{
			free(line);
			msg_free_exit(minirt, ERR_DOUBLE_A);
		}
		minirt->camera = (void*)new_camera();
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
			msg_free_exit(minirt, ERR_DOUBLE_L);
		}
		minirt->light = (void*)new_light();
		light_parameter(line, minirt);
	}
	if (type == 4)
	{
		obj->type = 4;
		obj->object = (void*)new_sphere();
		sphere_parameter(line, minirt, obj);
	}
	// if (type == 5)
	// {
	// 	obj->type = 5;
	// 	obj->object = (void*)new_plane();
	// }
	// if (type == 6)
	// {
	// 	obj->type = 6;
	// 	obj->object = (void*)new_cylinder();
	// }
}