#include "minirt.h"

t_sphere    *init_sphere(t_vect center, double radius)
{
    t_sphere    *ret;

    ret = malloc(sizeof(t_sphere));
    if (!ret)
        return (NULL);
    ret->center = center;
    ret->radius = radius;
    return (ret);
}