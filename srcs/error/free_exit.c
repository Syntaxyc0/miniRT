/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/23 15:59:20 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_exit(t_minirt *minirt)
{
	free_minirt(minirt);
	exit(EXIT_FAILURE);
}

void	msg_free_exit(t_minirt *minirt, char *msg)
{
	print_error(msg);
	free_minirt(minirt);
	exit(EXIT_FAILURE);
}

void	free_minirt(t_minirt *minirt)
{
	t_objects	*tmp;
	
	if (minirt->ambiant)
		free(minirt->ambiant);
	if (minirt->camera)
		free(minirt->camera);
	if (minirt->light)
		free(minirt->light);
	if (minirt->objects)
	{
		while (minirt->objects)
		{
			if (minirt->objects->object)
				free(minirt->objects->object);
			tmp = minirt->objects;
			minirt->objects = minirt->objects->next;
			free(tmp);
		}
	}
	free(minirt);
}

void	msg_free_line_exit(t_minirt *minirt, char *line, char *msg)
{
	print_error(msg);
	free(line);
	free_minirt(minirt);
	exit(EXIT_FAILURE);
}
