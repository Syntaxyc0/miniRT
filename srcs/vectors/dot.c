#include "minirt.h"

double  dot(t_vect a, t_vect b)
{
    return (a.x * b.x + a.y * b.y + a.z *b.z);
}