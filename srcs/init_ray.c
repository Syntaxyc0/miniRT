/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:05:03 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 16:33:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	init_ray(t_vect	origin, t_vect direction)
{
	t_ray	ret;

	ret.start = origin;
	ret.dir = direction;
	ret.inter = init_vect(0, 0, 0);
	ret.normal = init_vect(0, 0, 0);
	ret.inter_distance = INFINITY;
	ret.color = init_black();
	return (ret);
}
