#include "minirt.h"

t_vect  init_vect(float x, float y, float z)
{
    t_vect  ret;

    ret.x = x;
    ret.y = y;
    ret.z = z;

    return (ret);
}