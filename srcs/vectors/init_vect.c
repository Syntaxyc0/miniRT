#include "minirt.h"

t_vect  init_vect(double x, double y, double z)
{
    t_vect  ret;

    ret.x = x;
    ret.y = y;
    ret.z = z;

    return (ret);
}