/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:40:05 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:11:05 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	range_double(double x, double min, double max)
{
	if (x < min || x > max)
		return (1);
	return (0);
}

int	range_vector(t_vect vect, double min, double max)
{
	if (vect.x < min || vect.x > max)
		return (1);
	if (vect.y < min || vect.y > max)
		return (1);
	if (vect.z < min || vect.z > max)
		return (1);
	return (0);
}
