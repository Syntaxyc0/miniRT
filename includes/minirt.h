#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"

#define EPS 1e-6

typedef struct s_vect
{
    float  x;
    float  y;
    float  z;
}   t_vect;

typedef struct s_color
{
    unsigned int 	red;	
    unsigned int	green;
    unsigned int	blue;
}   t_color;

typedef struct s_ray
{
    t_vect  start;
    t_vect  dir;
	t_vect	inter;
	t_vect	normal;
	float	inter_distance;
	unsigned int	color;
}   t_ray;

typedef struct s_sphere
{
    t_vect center;
    float  radius;
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
	t_color	color;	
	float	diameter;
	float	height;
}	t_cylinder;

// Vectors

float  dot(t_vect a, t_vect b);
t_vect  add_v(t_vect a, t_vect b);
t_vect  substract_v(t_vect a, t_vect b);
t_vect  mult_v(t_vect a, float t);
float  norm_v(t_vect a);
t_vect  vect_product(t_vect a, t_vect b);
t_vect  normalize_v(t_vect a);
t_vect  init_vect(float x, float y, float z);
float	compute_dist(t_vect a, t_vect b);

int         intersphere(t_sphere *sphere, t_ray ray, float *t);
t_sphere    *init_sphere(t_vect center, float radius, t_color color);

t_plane *init_plane(t_vect point, t_vect normal, t_color color);
int	interplane(t_plane *plane, t_ray ray, float *t);
int	get_intersecton_plane(t_plane *plane, t_ray *ray, float *t);

t_cylinder	*init_cylinder(t_vect point, t_vect normal, float diameter, float height, t_color color);
int	intercylinder(t_cylinder *cyl, t_ray ray, float *t);
void	inter_cylinder_bot(t_cylinder *cyl, t_ray *ray, float *t);

t_ray	init_ray(t_vect	origin, t_vect direction);
t_vect  get_intersection_point(t_ray ray, float t);
int solve_quadratic_equation(float a, float b, float c, float *t);
unsigned int	rgb_to_hex(t_color color);

#endif