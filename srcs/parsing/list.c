/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:01:47 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/16 15:43:53 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_obj(int	type, t_objects **obj, char *line)
{
	if (!obj)
	{
		*obj = new_struct_object();
		obj = &*obj;
	}
	else
	{
		*obj = last_obj(obj);
		(*obj)->next = new_struct_object();
		*obj = (*obj)->next;
	}
	obj_type(*obj, type, line, obj);
}

t_objects	*last_obj(t_objects **obj)
{
	while (*obj)
		*obj = (*obj)->next;
	return (*obj);
}

t_objects	*new_struct_object(void)
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
}

void	obj_type(t_objects *obj, int type, char *line, t_objects **objects)
{
	if (type == 1)
	{
		obj->type = 1;
		obj->object = (void*)new_ambiant();
		ambiant_parameter(line, type, obj, objects);
	}
	if (type == 2)
	{
		obj->type = 2;
		obj->object = (void*)new_camera();
	}
	if (type == 3)
	{
		obj->type = 3;
		obj->object = (void*)new_light();
	}
	obj_type2(obj, type);
}

void	obj_type2(t_objects *obj, int type, t_objects **objects)
{
	if (type == 4)
	{
		obj->type = 4;
		obj->object = (void*)new_sphere();
	}
	if (type == 5)
	{
		obj->type = 5;
		obj->object = (void*)new_plane();
	}
	if (type == 6)
	{
		obj->type = 6;
		obj->object = (void*)new_cylinder();
	}
}