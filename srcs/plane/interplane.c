/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interplane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:33 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 16:23:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	interplane(t_plane *plane, t_ray ray, double *t)
{
	double	denom;

	plane->normal = normalize_v(plane->normal);
	denom = dot(plane->normal, ray.dir);
	if (fabs(denom) > EPS)
	{
		*t = dot(plane->normal, substract_v(plane->point, ray.start)) / denom;
		if (*t > EPS)
			return (1);
	}
	return (0);
}

int	get_intersection_plane(t_plane *plane, t_ray *ray, double *t)
{
	t_vect	inter;
	double	dist;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(ray->start, inter);
	if (dist < EPS || dist >= ray->inter_distance)
		return (0);
	ray->inter = inter;
	ray->normal = plane->normal;
	if (dot(ray->dir, plane->normal) > 0)
		ray->normal = mult_v(plane->normal, -1);
	ray->inter_distance = dist;
	ray->color = plane->color;
	return (1);
}
