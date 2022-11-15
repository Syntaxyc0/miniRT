/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:50:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/15 12:56:29 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objects	init_struct_object(void);
{
	t_objects obj;

	obj = malloc(sizeof(t_objects));
	if (!obj)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	obj.type = 0;
	obj.object = 0;
	obj.next = 0;
}