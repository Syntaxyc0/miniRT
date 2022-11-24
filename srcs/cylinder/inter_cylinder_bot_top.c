#include "minirt.h"

int	inter_cylinder_bot(t_cylinder *cyl, t_ray *ray, float *t)
{
	t_plane *plane;

	plane = (t_plane *)cyl;
	if (interplane(plane, *ray, t))
		return (1);
	return (0);
}

void	get_intersection_bot_point(t_cylinder *cyl, t_ray *ray, float *t)
{
	t_vect	inter;
	float	dist;
	float	dist_to_center;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(inter, ray->start);
	dist_to_center = compute_dist(inter, cyl->point);
	if (dist < EPS || dist >= ray->inter_distance || dist_to_center > cyl->diameter / 2)
		return ;
	ray->inter = inter;
	ray->normal = mult_v(cyl->normal, -1);
	ray->inter_distance = dist;
	ray->color = rgb_to_hex(cyl->color);

}

t_plane *init_top_plane(t_cylinder *cyl)
{
	t_plane	*ret;

	ret = NULL;
	ret->point = add_v(cyl->point, mult_v(normalize_v(cyl->normal), cyl->height));
	ret->normal = cyl->normal;
	ret->color = cyl->color;
	return (ret);
}

int	inter_cylinder_top(t_cylinder *cyl, t_ray *ray, float *t)
{
	t_plane	*plane;

	plane= init_top_plane(cyl);
	if (interplane(plane, *ray, t))
		return (1);
	return (0);
}

void	get_intersection_top_point(t_cylinder *cyl, t_ray *ray, float *t)
{
	t_vect	inter;
	float	dist;
	float	dist_to_center;

	inter = get_intersection_point(*ray, *t);
	dist = compute_dist(inter, ray->start);
	dist_to_center = compute_dist(inter, cyl->point);
	if (dist < EPS || dist >= ray->inter_distance || dist_to_center > cyl->diameter / 2)
		return ;
	ray->inter = inter;
	ray->normal = cyl->normal;
	ray->inter_distance = dist;
	ray->color = rgb_to_hex(cyl->color);
}