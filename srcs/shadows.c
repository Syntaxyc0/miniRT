/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:05:10 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:05:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_obj(t_objects *obj, t_ray *ray)
{
	float	t;
	t_vect	point;
	float	dist;

	t = 0;
	if (obj->type == 4)
	{
		if (intersphere((t_sphere *)obj->object, *ray, &t))
		{
			point = get_intersection_point(*ray, t);
			dist = compute_dist(ray->start, point);
			if (dist < ray->inter_distance)
				return (1);
		}
	}
	else if (obj->type == 5)
	{
		if (interplane((t_plane *)obj->object, *ray, &t))
		{
			point = get_intersection_point(*ray, t);
			dist = compute_dist(ray->start, point);
			if (dist < ray->inter_distance)
				return (1);
		}
	}
	else if (obj->type == 6)
	{
		if (intercylinder((t_cylinder *)obj->object, *ray, &t))
		{
			point = get_intersection_point(*ray, t);
			dist = compute_dist(ray->start, point);
			if (dist < ray->inter_distance)
				return (1);
		}
	}
	return (0);
}

void	check_shadow_intersect(t_minirt *mini, t_ray *ray)
{
	t_objects	*obj;
	int	is_in_shadow;
	float	angle;
	unsigned int	nuance_color;

	is_in_shadow = 0;
	obj = mini->objects;
	while (obj)
	{
		if (intersect_obj(obj, ray))
		{
			is_in_shadow = 1;
			break ;
		}
		obj = obj->next;
	}
	if (is_in_shadow)
		ray->color = apply_coeff_color(ray->color, mini->ambiant->color, mini->ambiant->intensity);
	else
	{
		angle = dot(ray->dir, ray->normal);
		if (angle > 0)
		{
			nuance_color = apply_coeff(ray->color, angle * mini->light->intensity);
			ray->color = add_color(ray->color, nuance_color);
		}
	}

}

void	shadows(t_minirt *mini, t_ray ray)
{
	t_ray	shadow;
	t_vect	dir;

	dir = substract_v(mini->light->position, ray.inter);
	shadow = init_ray(add_v(ray.inter, mult_v(dir, EPS)), dir);
	shadow.inter = mini->light->position;
	shadow.inter_distance = norm_v(shadow.dir);
	shadow.color = ray.color;
	shadow.dir = normalize_v(shadow.dir);
	check_shadow_intersect(mini, &shadow);
}