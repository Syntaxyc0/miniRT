/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cyl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:36:54 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 15:36:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	resolve_cyl(t_cylinder *cyl, t_ray *ray, t_res res, double *t)
{
	double	r0;
	double	r1;
	double	h0;
	double	h1;

	r0 = (-1 * res.b + sqrtf(res.delta)) / (2 * res.a);
	r1 = (-1 * res.b - sqrtf(res.delta)) / (2 * res.a);
	if (r0 < EPS)
		return (0);
	h0 = dot(ray->dir, cyl->normal) * r0
		+ dot(substract_v(ray->start, cyl->point), cyl->normal);
	h1 = dot(ray->dir, cyl->normal) * r1
		+ dot(substract_v(ray->start, cyl->point), cyl->normal);
	if (h1 > EPS && h1 <= cyl->height)
	{
		*t = r1;
		return (1);
	}
	if (h0 > EPS && h0 <= cyl->height)
	{
		*t = r0;
		return (1);
	}
	return (0);
}

int	inter_cylinder_pipe(t_cylinder *cyl, t_ray *ray, double *t)
{
	t_res	res;
	t_vect	cyl_ray;

	cyl->normal = normalize_v(cyl->normal);
	cyl_ray = substract_v(ray->start, cyl->point);
	res.a = 1 - powf(dot(ray->dir, cyl->normal), 2);
	res.b = 2 * (dot(cyl_ray, ray->dir)
			- dot(cyl->normal, ray->dir) * dot(cyl->normal, cyl_ray));
	res.c = powf(norm_v(cyl_ray), 2)
		- powf(dot(cyl_ray, cyl->normal), 2) - powf(cyl->diameter / 2, 2);
	res.delta = res.b * res.b - 4 * res.a * res.c;
	if (res.delta < 0)
		return (0);
	if (resolve_cyl(cyl, ray, res, t))
		return (1);
	return (0);
}

void	get_intersection_cylinder_pipe(t_cylinder *cyl, t_ray *ray, double *t)
{
	t_vect	inter;
	double	dist;
	double	len;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(ray->start, inter);
	if (dist < EPS || dist >= ray->inter_distance)
		return ;
	ray->color = cyl->color;
	ray->inter = inter;
	ray->inter_distance = dist;
	len = dot(ray->dir, mult_v(cyl->normal, *t))
		+ dot(substract_v(ray->start, cyl->point), cyl->normal);
	ray->normal = normalize_v(substract_v(
				substract_v(inter, cyl->point), mult_v(cyl->normal, len)));
}

int	inter_cylinder_bot(t_cylinder *cyl, t_ray *ray, double *t)
{
	t_plane	*plane;
	t_vect	inter;
	double	dist;
	double	dist_to_center;

	plane = (t_plane *)cyl;
	if (interplane(plane, *ray, t))
	{
		inter = get_intersection_point(*ray, *t);
		dist = compute_dist(inter, ray->start);
		dist_to_center = compute_dist(inter, cyl->point);
		if (dist < EPS || dist >= ray->inter_distance
			|| dist_to_center > cyl->diameter / 2 + EPS)
			return (0);
		else
			return (1);
	}
	return (0);
}

void	get_intersection_bot_point(t_cylinder *cyl, t_ray *ray, double *t)
{
	t_vect	inter;
	double	dist;
	double	dist_to_center;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(inter, ray->start);
	dist_to_center = compute_dist(inter, cyl->point);
	if (dist < EPS || dist >= ray->inter_distance
		|| dist_to_center > cyl->diameter / 2 + EPS)
		return ;
	ray->inter = inter;
	ray->inter_distance = dist;
	ray->color = cyl->color;
	ray->normal = cyl->normal;
}
