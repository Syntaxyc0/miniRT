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

typedef struct s_ray
{
    t_vect  start;
    t_vect  dir;
}   t_ray;

typedef struct s_sphere
{
    t_vect center;
    double  radius;
}   t_sphere;



// Vectors

double  dot(t_vect a, t_vect b);
t_vect  add_v(t_vect a, t_vect b);
t_vect  substract_v(t_vect a, t_vect b);
t_vect  mult_v(t_vect a, double t);
double  norm_v(t_vect a);
t_vect  vect_product(t_vect a, t_vect b);
t_vect  normalize_v(t_vect a);


#endif