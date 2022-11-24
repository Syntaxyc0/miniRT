/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_spe2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:38:59 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:02:57 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*new_plane(void)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	return (plane);
}

t_cylinder	*new_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
	{
		print_error(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
	return (cylinder);
}
