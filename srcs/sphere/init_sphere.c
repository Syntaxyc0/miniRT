#include "minirt.h"

t_sphere    *init_sphere(t_vect center, double radius, t_color color)
{
    t_sphere    *ret;

    ret = malloc(sizeof(t_sphere));
    if (!ret)
        return (NULL);
    ret->center = center;
    ret->radius = radius;
    ret->color.red = color.red;
    ret->color.green = color.green;
    ret->color.blue = color.blue;
    return (ret);
}