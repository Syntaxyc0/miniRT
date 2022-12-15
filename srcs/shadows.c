/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:05:10 by marvin            #+#    #+#             */
/*   Updated: 2022/12/15 10:54:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_dist(t_ray *ray, double *t)
{
	t_vect	point;
	double	dist;

	point = get_intersection_point(*ray, *t);
	dist = compute_dist(ray->start, point);
	if (dist < ray->inter_distance)
		return (1);
	return (0);
}

int	intersect_obj(t_objects *obj, t_ray *ray)
{
	double	t;
	int check;

	t = 0;
	check = 0;
	if (obj->type == 4)
	{
		if (intersphere((t_sphere *)obj->object, *ray, &t))
			return (check_dist(ray, &t));
	}
	else if (obj->type == 5)
	{
		if (interplane((t_plane *)obj->object, *ray, &t))
			return (check_dist(ray, &t));
	}
	else if (obj->type == 6)
	{
		if (inter_cylinder_pipe((t_cylinder *)obj->object, ray, &t))
			check = check_dist(ray, &t);
		return (check);
	}
	return (0);
}

void	get_color(t_minirt *mini, t_ray *ray)
{
	double			angle;
	t_color	nuance_color;

	angle = dot(ray->dir, ray->normal);
	ray->color = apply_coeff_color(ray->color,
			mini->ambiant->color, mini->ambiant->intensity);
	
	if (angle > EPS)
	{
		nuance_color = apply_coeff_color(ray->color,
				init_white(), angle * mini->light->intensity);
		ray->color = add_color_v(ray->color, nuance_color);
	}
}

void	check_shadow_intersect(t_minirt *mini, t_ray *ray)
{
	t_objects		*obj;
	int				is_in_shadow;
	t_color	nuance_color;

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
	{
		ray->color = apply_coeff_color(ray->color,
			mini->ambiant->color, mini->ambiant->intensity);
		nuance_color = apply_coeff_color(ray->color,
				init_white(), 0);
		ray->color = add_color_v(ray->color, nuance_color);
	}
	else
		get_color(mini, ray);
}

t_color	shadows(t_minirt *mini, t_ray *ray)
{
	t_ray	shadow;
	t_vect	dir;

	if (ray->inter_distance != INFINITY && mini->light)
	{
		dir = substract_v(mini->light->position, ray->inter);
		shadow = init_ray(add_v(ray->inter, mult_v(dir, 1e-5)), dir);
		shadow.inter = mini->light->position;
		shadow.inter_distance = norm_v(shadow.dir);
		shadow.color = ray->color;
		shadow.dir = normalize_v(shadow.dir);
		shadow.normal = ray->normal;
		if (dot(ray->dir, shadow.normal) > EPS)
			shadow.normal = mult_v(shadow.normal, -1);
		check_shadow_intersect(mini, &shadow);
		return (shadow.color);
	}
	else
	{
		return (apply_coeff(mini->ambiant->color,
			mini->ambiant->intensity));
	}
}
