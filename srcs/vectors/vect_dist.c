#include "minirt.h"

float	compute_dist(t_vect a, t_vect b)
{
	return (sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2) + powf(a.z - b.z, 2)));
}