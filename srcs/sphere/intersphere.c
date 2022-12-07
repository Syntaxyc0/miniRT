/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:40 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:04:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int solve_quadratic_equation(float a, float b, float c, float *t)
{
    float  delta;
    float  r0;
    float  r1;

    delta = b * b - 4.0 * a * c;
    if (delta < 0)
        return (0);
    else if (delta == 0)
        *t = -1 * b / (2 * a);
    else
    {
        r0 = (-1 * b - sqrtf(delta)) / (2 * a);
        r1 = (-1 * b + sqrtf(delta)) / (2 * a);
        if (r0 <= 0 || r1 <= 0)
            return(0);
        if (r0 < r1)
            *t = r0;
        else
            *t = r1;
    }
    return (1);
}

int intersphere(t_sphere *sphere, t_ray ray, float *t)
{
    float  a;
    float  b;
    float  c;

    a = dot(ray.dir, ray.dir);
    b = 2.0 * dot(ray.dir, substract_v(ray.start, sphere->center));
    c = dot(substract_v(ray.start, sphere->center), substract_v(ray.start, sphere->center)) - sphere->radius * sphere->radius;
    if (solve_quadratic_equation(a, b, c, t))
        return (1);
    return (0);
}

int	get_intersecton_sphere(t_sphere *sphere, t_ray *ray, float *t)
{
	t_vect	inter;
	float	dist;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(ray->start, inter);
	if (dist < EPS || dist >= ray->inter_distance)
		return (0);
	ray->inter = inter;
	ray->normal = substract_v(inter, sphere->center);
	ray->inter_distance = dist;
	ray->color = rgb_to_hex(sphere->color);
	return (1);
}