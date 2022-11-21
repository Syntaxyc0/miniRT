#include "minirt.h"

t_ray	init_ray(t_vect	origin, t_vect direction)
{
	t_ray	ret;

	ret.start = origin;
	ret.dir = direction;
	ret.inter = init_vect(0,0,0);
	ret.normal = init_vect(0,0,0);
	ret.inter_distance = INFINITY;
	ret.color = 0;
	return (ret);
}