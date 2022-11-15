#include "minirt.h"

t_cylinder	*init_cylinder(t_vect point, t_vect normal, double diameter, double height, t_color color)
{
	t_cylinder	*ret;

	ret = malloc(sizeof(t_cylinder));
	if (!ret)
		return (NULL);
	ret->point = point;
	ret->normal = normal;
	ret->diameter = diameter;
	ret->height = height;
	ret->color = color;
	return (ret);
}