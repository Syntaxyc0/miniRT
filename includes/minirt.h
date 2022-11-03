#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_vect
{
    double  x;
    double  y;
    double  z;
}   t_vect;

double  dot(t_vect a, t_vect b);

#endif