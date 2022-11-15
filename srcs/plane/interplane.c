#include "minirt.h"

int	interplane(t_plane *plane, t_ray ray, double *t)
{
	double	denom;

	denom = dot(plane->normal, ray.dir);
	if (fabs(denom) > 0.000001)
	{
		*t = dot(plane->normal, substract_v(plane->point, ray.start)) / denom;
		if (*t < 0)
			return (0);
		else
			return (1); 
	}
	else
		return (0);
}