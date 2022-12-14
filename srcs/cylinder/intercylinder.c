/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:47 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 15:36:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	inter_cylinder_pipe(t_cylinder *cyl, t_ray *ray, double *t)
{
	t_vect	cyl_ray;
	double	a;
	double	b;
	double	c;
	t_vect	point;

	cyl_ray = substract_v(ray->start, cyl->point);
	a = powf(norm_v(cyl_ray), 2)
		- powf(dot(ray->dir, cyl->normal), 2);
	b = 2 * dot(cyl_ray, ray->dir)
		- dot(cyl->normal, ray->dir) * (dot(cyl->normal, cyl_ray));
	c = powf(norm_v(cyl_ray), 2)
		- powf(dot(cyl_ray, cyl->normal), 2) - powf(cyl->diameter / 2, 2);
	if (solve_quadratic_equation(a, b, c, t))
	{
		point = get_intersection_point(*ray, *t);
		if (dot(substract_v(point, cyl->point),
				cyl->normal) < 0)
			return (0);
		else if (sqrtf(powf(norm_v(point), 2)
				- powf(cyl->diameter / 2, 2)) > cyl->height)
			return (0);
		return (1);
	}
	return (0);
}

void	get_intersection_cylinder_pipe(t_cylinder *cyl, t_ray *ray, double *t)
{
	t_vect	inter;
	double	dist;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(ray->start, inter);
	if (dist < EPS || dist >= ray->inter_distance)
		return ;
	ray->inter = inter;
	ray->normal = substract_v(inter, add_v(cyl->point,
				mult_v(cyl->normal, dot(inter, cyl->normal))));
	ray->inter_distance = dist;
	ray->color = cyl->color;
}

void	get_intersect_cylinder(t_cylinder *cyl, t_ray *ray, double *t)
{
	if (inter_cylinder_bot(cyl, ray, t))
		get_intersection_bot_point(cyl, ray, t);
	if (inter_cylinder_top(cyl, ray, t))
		get_intersection_top_point(cyl, ray, t);
	if (inter_cylinder_pipe(cyl, ray, t))
		get_intersection_cylinder_pipe(cyl, ray, t);
}

int	intercylinder(t_cylinder *cyl, t_ray ray, double *t)
{
	if (inter_cylinder_bot(cyl, &ray, t))
		return (1);
	if (inter_cylinder_top(cyl, &ray, t))
		return (1);
	if (inter_cylinder_pipe(cyl, &ray, t))
		return (1);
	return (0);
}
