/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection_point.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:05:00 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 16:32:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	get_intersection_point(t_ray ray, double t)
{
	t_vect	ret;

	ret = add_v(ray.start, mult_v(ray.dir, t));
	return (ret);
}