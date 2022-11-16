/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/16 14:47:44 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_objects(t_objects **obj)
{
	t_objects	*tmp;
	while (*obj)
	{
		if ((*obj)->object)
			free_object(*obj);
		tmp = *obj;
		*obj = (*obj)->next;
		free(tmp);
	}
}

void	free_object(t_objects *obj)
{
	if (obj->type == 1)
		free_ambiant(obj);
	if (obj->type == 2)
		free_camera(obj);
	if (obj->type == 3)
		free_light(obj);
	if (obj->type == 4)
		free_shpere(obj);
	if (obj->type == 5)
		free_plane(obj);
	if (obj->type == 6)
		free_clinder(obj);
}

void	free_ambiant(t_objects *obj)
{
	t_ambiant	*ambiant;

	ambiant = obj->object;
	if (*(ambiant)->color)
		free(ambiant->color);
		
}