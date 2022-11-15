/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:47:30 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/15 12:58:45 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include <fcntl.h>

# define ERR_NBARGS "wrong number of args"
# define ERR_TYPEARG "must be a .rt"
# define ERR_MALLOC "malloc failed"

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
    t_vect  point;
    t_vect  normal;
	double	diameter;
	double	height;
    t_color color;
}   t_cylinder;

typedef struct	s_objects
{
	int					type;
	void				*object;
	struct s_objects	*next;
}	t_objects;

/*
1 = A (lumiere ambiante)
2 = C (camera)
3 = L (lumiere)
4 = sp
5 = pl
6 = cy
*/

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

t_vect  get_intersection_point(t_ray ray, double t);

// Parsing

void	parsing(int fd, int ac, char **av);
int 	check_args(int ac, char **av);
int		is_rt(char *str);
int		str_big(char *str1, char *str2);

// Error

void	print_error(char *msg);

#endif