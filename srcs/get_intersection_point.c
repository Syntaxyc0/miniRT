#include "minirt.h"

t_vect  get_intersection_point(t_ray ray, float t)
{
    t_vect  ret;

    ret = add_v(ray.start, mult_v(ray.dir, t));
    return (ret);
}