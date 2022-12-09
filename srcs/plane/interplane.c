/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interplane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:33 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:04:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	interplane(t_plane *plane, t_ray ray, float *t)
{
	float	denom;

	denom = dot(plane->normal, ray.dir);
	if (fabs(denom) > EPS)
	{
		*t = dot(plane->normal, substract_v(plane->point, ray.start)) / denom;
		if (*t < 0)
			return (0);
		else
			return (1); 
	}
	else
		return (0);
}

int	get_intersection_plane(t_plane *plane, t_ray *ray, float *t)
{
	t_vect	inter;
	float	dist;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(ray->start, inter);
	if (dist < EPS || dist >= ray->inter_distance)
		return (0);
	ray->inter = inter;
	ray->normal = plane->normal;
	if (dot(ray->dir, plane->normal))
		ray->normal = mult_v(plane->normal, -1);
	ray->inter_distance = dist;
	ray->color = rgb_to_hex(plane->color);
	return (1);
}