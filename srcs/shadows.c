#include "minirt.h"

int	intersect_obj(t_objects *obj, t_ray *ray)
{
	float	t;
	t_vect	point;
	float	dist;

	t = 0;
	if (obj->type == 4)
	{
		if (intersphere((t_sphere *)obj->object), *ray, &t)
		{
			point = get_intersection_point(*ray, t);
			dist = compute_dist(ray->start, point);
			if (dist < ray->inter_distance)
				return (1);
		}
	}
	else if (obj->type == 5)
	{
		if (interplane((t_plane *)obj->object), *ray, &t)
		{
			point = get_intersection_point(*ray, t);
			dist = compute_dist(ray->start, point);
			if (dist < ray->inter_distance)
				return (1);
		}
	}
	else if (obj->type == 6)
	{
		if (intercylinder((t_cylinder *)obj->object), *ray, &t)
		{
			point = get_intersection_point(*ray, t);
			dist = compute_dist(ray->start, point);
			if (dist < ray->inter_distance)
				return (1);
		}
	}
	return (0);
}

void	check_shadow_intersect(t_minirrt *mini, t_ray *ray)
{
	t_objects	*obj;
	int	is_in_shadow;

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
		
	}

}

void	shadows(t_minirt *mini, t_ray ray)
{
	t_ray	shadow;
	t_vect	dir;

	dir = substract_v(ray.inter, mini->light->position);
	shadow = init_ray(add_v(ray.inter, mult_v(dir, EPS)), dir);
	shadow.inter = mini->light->position;
	shadow.inter_distance = norm_v(shadow.dir);
	shadow.color = ray.color;
	check_shadow_intersect(mini, &shadow);
}