/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:40 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 16:26:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	solve_quadratic_equation(double a, double b, double c, double *t)
{
	double	delta;
	double	r0;
	double	r1;

	delta = b * b - 4.0 * a * c;
	if (delta < EPS)
		return (0);
	r0 = (-1 * b - sqrtf(delta)) / (2 * a);
	r1 = (-1 * b + sqrtf(delta)) / (2 * a);
	if (r0 * r1 > EPS)
	{
		if (r0 > EPS)
		{
			*t = r0;
			return (1);
		}
		return (0);
	}
	if (r0 > EPS)
	{
		*t = r0;
		return (1);
	}
	*t = r1;
	return (1);
}

int	intersphere(t_sphere *sphere, t_ray ray, double *t)
{
	double	a;
	double	b;
	double	c;

	a = dot(ray.dir, ray.dir);
	b = 2.0 * dot(ray.dir, substract_v(ray.start, sphere->center));
	c = dot(substract_v(ray.start, sphere->center), substract_v(ray.start,
				sphere->center)) - sphere->radius * sphere->radius;
	if (solve_quadratic_equation(a, b, c, t))
		return (1);
	return (0);
}

int	get_intersection_sphere(t_sphere *sphere, t_ray *ray, double *t)
{
	t_vect	inter;
	double	dist;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(ray->start, inter);
	if (dist < 0 || dist > ray->inter_distance)
		return (0);
	ray->normal = substract_v(inter, sphere->center);
	ray->inter = inter;
	ray->normal = normalize_v(ray->normal);
	ray->inter_distance = dist;
	ray->color = sphere->color;
	return (1);
}
