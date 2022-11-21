/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/21 14:53:13 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_exit(t_objects **obj)
{
	free_objects(obj);
	exit(EXIT_FAILURE);
}

void	msg_free_exit(t_objects **obj, char *msg)
{
	print_error(msg);
	free_objects(obj);
	exit(EXIT_FAILURE);
}

void	free_objects(t_objects **obj)
{
	t_objects	*tmp;
	
	if (!obj)
		return ;
	while (*obj)
	{
		if ((*obj)->object)
			free((*obj)->object);
		tmp = *obj;
		*obj = (*obj)->next;
		free(tmp);
	}
}
