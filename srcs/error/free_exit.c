/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/22 14:45:43 by ggobert          ###   ########.fr       */
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
	
	if (!minirt->objects)
	{
		free(minirt);
		return ;
	}
	while (minirt->objects->object)
	{
		if (minirt->objects->object)
			free(minirt->objects->object);
		tmp = minirt->objects->object;
		minirt->objects = minirt->objects->next;
		free(tmp);
	}
	free(minirt);
}
