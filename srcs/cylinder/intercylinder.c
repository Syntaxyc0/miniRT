#include "minirt.h"

int	intercylinder(t_cylinder *cyl, t_ray ray, double *t)
{
	double	a;
	double	b;
	double	c;

	a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2);
	b = 2 * (ray.start.x * ray.dir.x + ray.start.y * ray.dir.y);
	c = pow(ray.start.x, 2) + pow(ray.start.y, 2) - pow(cyl->diameter / 2, 2);
	if (solve_equation(a, b, c, t))
		return (1);
	return (0);
}