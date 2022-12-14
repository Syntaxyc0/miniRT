/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder_bot_top.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:43 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 16:42:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int	inter_cylinder_bot(t_cylinder *cyl, t_ray *ray, double *t)
// {
// 	t_plane	*plane;
// 	t_vect	inter;
// 	double	dist;
// 	double	dist_to_center;

// 	plane = (t_plane *)cyl;
// 	if (interplane(plane, *ray, t))
// 	{
// 		inter = get_intersection_point(*ray, *t);
// 		dist = compute_dist(inter, ray->start);
// 		dist_to_center = compute_dist(inter, cyl->point);
// 		if (dist < EPS || dist >= ray->inter_distance
// 			|| dist_to_center > cyl->diameter / 2 + EPS)
// 			return (0);
// 		else
// 			return (1);
// 	}
// 	return (0);
// }

// void	get_intersection_bot_point(t_cylinder *cyl, t_ray *ray, double *t)
// {
// 	t_vect	inter;
// 	double	dist;
// 	double	dist_to_center;

// 	inter = get_intersection_point(*ray, *t);
// 	dist = compute_dist(inter, ray->start);
// 	dist_to_center = compute_dist(inter, cyl->point);
// 	if (dist < EPS || dist >= ray->inter_distance
// 		|| dist_to_center > cyl->diameter / 2 + EPS)
// 		return ;
// 	ray->inter = inter;
// 	ray->inter_distance = dist;
// 	ray->color = cyl->color;
// }

t_plane	*init_top_plane(t_cylinder *cyl)
{
	t_plane	*ret;

	ret = malloc(sizeof(t_plane));
	ret->point = substract_v(cyl->point,
			mult_v(normalize_v(cyl->normal), cyl->height));
	ret->normal = mult_v(cyl->normal, -1);
	ret->color = cyl->color;
	return (ret);
}

int	inter_cylinder_top(t_cylinder *cyl, t_ray *ray, double *t)
{
	t_vect	inter;
	t_plane	*plane;
	double	dist;
	double	dist_to_center;

	plane = init_top_plane(cyl);
	if (interplane(plane, *ray, t))
	{
		free(plane);
		inter = get_intersection_point(*ray, *t);
		dist = compute_dist(inter, ray->start);
		dist_to_center = compute_dist(inter, cyl->point);
		if (dist < EPS || dist >= ray->inter_distance
			|| dist_to_center > cyl->diameter / 2)
			return (0);
		else
			return (1);
	}
	free(plane);
	return (0);
}

void	get_intersection_top_point(t_cylinder *cyl, t_ray *ray, double *t)
{
	t_vect	inter;
	double	dist;
	double	dist_to_center;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(inter, ray->start);
	dist_to_center = compute_dist(inter, cyl->point);
	if (dist < EPS || dist >= ray->inter_distance
		|| dist_to_center > cyl->diameter / 2)
		return ;
	ray->inter = inter;
	ray->normal = cyl->normal;
	ray->inter_distance = dist;
	ray->color = cyl->color;
}
