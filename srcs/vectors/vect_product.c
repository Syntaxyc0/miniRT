#include "minirt.h"

t_vect  vect_product(t_vect a, t_vect b)
{
    t_vect  ret;

    ret.x = a.y * b.z - a.z * b.y;
    ret.y = a.z * b.x - a.x * b.z;
    ret.z = a.x * b.y - a.y * b.x;

    return (ret);
}