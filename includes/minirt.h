/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:47:30 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/16 14:30:56 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define ERR_NBARGS "wrong number of args"
# define ERR_TYPEARG "must be a .rt"
# define ERR_MALLOC "malloc failed"
# define ERR_ID "id unknown"

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

typedef struct s_ambiant
{
	double	intensity;
	t_color	color;
}	t_ambiant;

typedef struct	s_camera
{
	t_vect	position;
	t_vect	orientation;
	double	angle;
}	t_camera;

typedef struct s_light
{
	t_vect	position;
	double	intensity;
}	t_light;

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

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

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
int		intercylinder(t_cylinder *cyl, t_ray ray, float *t);
int		inter_cylinder_bot(t_cylinder *cyl, t_ray *ray, float *t);
void	get_intersection_bot_point(t_cylinder *cyl, t_ray *ray, float *t);
int		inter_cylinder_top(t_cylinder *cyl, t_ray *ray, float *t);
void	get_intersection_top_point(t_cylinder *cyl, t_ray *ray, float *t);

t_ray	init_ray(t_vect	origin, t_vect direction);
t_vect  get_intersection_point(t_ray ray, float t);
int solve_quadratic_equation(float a, float b, float c, float *t);
unsigned int	rgb_to_hex(t_color color);
t_vect  get_intersection_point(t_ray ray, double t);

// Parsing

void		parsing(int fd, int ac, char **av, t_objects **obj);
void		init_id(char *line, char *id, t_objects **obj);
int 		check_args(int ac, char **av);
int			is_rt(char *str);
int			str_big(char *str1, char *str2);
t_objects	*new_struct_object(void);
t_objects	*last_obj(t_objects **obj);
t_ambiant	*new_ambiant(void);
t_camera	*new_camera(void);
t_light		*new_light(void);
t_sphere	*new_sphere(void);
t_plane		*new_plane(void);
t_cylinder	*new_cylinder(void);

// Error

void	print_error(char *msg);

#endif