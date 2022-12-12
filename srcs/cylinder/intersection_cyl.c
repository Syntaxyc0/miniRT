#include "minirt.h"

int	resolve_cyl(t_cylinder *cyl, t_ray *ray, t_res res, float *t)
{
	float	r0;
	float	r1;
	float	h0;
	float	h1;

	r0 = (-1 * res.b + sqrtf(res.delta)) / (2 * res.a);
	r1 = (-1 * res.b - sqrtf(res.delta)) / (2 * res.a);
	if (r0 < EPS)
		return (0);
	if (r0 > r1)
		*t = r1;
	else
		*t = r0;
	h0 = dot(ray->dir, cyl->normal) * r0 + dot(substract_v(ray->start, cyl->point), cyl->normal)
	h1 = dot(ray->dir, cyl->normal) * r1 + dot(substract_v(ray->start, cyl->point), cyl->normal)
	if (h0 >= EPS && h0 <= cyl->height)
	{
		*t = r0;
		return (1);
	}
	if (h1 >= EPS && h1 <= cyl->height)
	{
		*t = r1;
		return (1);
	}
	return (0);
}

int	inter_cylinder(t_cylinder *cyl, t_ray *ray, float *t)
{
	t_res	res;
	t_vect	cyl_ray;

	cyl->normal = normalize_v(cyl->normal);
	cyl_ray = substract_v(ray->start, cyl->point);
	res.a = 1 - powf(dot(ray->dir, cyl->normal), 2);
	res.b = 2 * (dot(cyl_ray, ray->dir) - dot(cyl->normal, ray->dir) * dot(cyl->normal, cyl_ray));
	res.c = powf(norm_v(cyl_ray), 2) - powf(dot(cyl_ray, cyl->normal), 2) - powf(cyl->diameter / 2, 2);
	res.delta = b * b - 4 * a * c;
	if (res.delta < EPS)
		return (0);
	if (resolve_cyl(cyl, ray, res, t))
		return (1);
	return (0);
}