#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"

typedef struct s_vect
{
    double  x;
    double  y;
    double  z;
}   t_vect;

typedef struct s_color
{
    double  red;
    double  green;
    double  blue;
}   t_color;

typedef struct s_ray
{
    t_vect  start;
    t_vect  dir;
}   t_ray;

typedef struct s_sphere
{
    t_vect center;
    double  radius;
    t_color color;
}   t_sphere;

typedef struct s_plane
{
    t_vect  point;
    t_vect  normal;
    t_color color;
}   t_plane;

typedef struct s_cylinder
{
	t_vect	point;
	t_vect	normal;
	double	diameter;
	double	height;
	t_color	color;	
}	t_cylinder;

// Vectors

double  dot(t_vect a, t_vect b);
t_vect  add_v(t_vect a, t_vect b);
t_vect  substract_v(t_vect a, t_vect b);
t_vect  mult_v(t_vect a, double t);
double  norm_v(t_vect a);
t_vect  vect_product(t_vect a, t_vect b);
t_vect  normalize_v(t_vect a);

int         intersphere(t_sphere *sphere, t_ray ray, double *t);
t_sphere    *init_sphere(t_vect center, double radius, t_color color);

t_plane *init_plane(t_vect point, t_vect normal, t_color color);
int	interplane(t_plane *plane, t_ray ray, double *t);

t_cylinder	*init_cylinder(t_vect point, t_vect normal, double diameter, double height, t_color color);
int	intercylinder(t_cylinder *cyl, t_ray ray, double *t);

t_vect  get_intersection_point(t_ray ray, double t);
int solve_equation(double a, double b, double c, double *t);



#endif