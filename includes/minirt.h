/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:47:30 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/21 14:50:48 by ggobert          ###   ########.fr       */
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
# define ERR_COLOR "wrong value of color"
# define ERR_INTENS "wrong value of intensity"

typedef struct s_vect
{
    float  x;
    float  y;
    float  z;
}   t_vect;

typedef struct s_color
{
    unsigned int	red;
    unsigned int	green;
    unsigned int	blue;
}   t_color;

typedef struct s_ray
{
    t_vect  start;
    t_vect	dir;
}   t_ray;

typedef struct s_ambiant
{
	float	intensity;
	t_color	color;
}	t_ambiant;

typedef struct	s_camera
{
	t_vect	position;
	t_vect	orientation;
	float	angle;
}	t_camera;

typedef struct s_light
{
	t_vect	position;
	float	intensity;
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
    t_vect  point;
    t_vect  normal;
    t_color color;
	float	diameter;
	float	height;
}   t_cylinder;

typedef struct	s_objects
{
	int					type;
	void				*object;
	struct s_objects	*next;
	char				**line;
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

float  dot(t_vect a, t_vect b);
t_vect  add_v(t_vect a, t_vect b);
t_vect  substract_v(t_vect a, t_vect b);
t_vect  mult_v(t_vect a, float t);
float  norm_v(t_vect a);
t_vect  vect_product(t_vect a, t_vect b);
t_vect  normalize_v(t_vect a);

int         intersphere(t_sphere *sphere, t_ray ray, float *t);
t_sphere    *init_sphere(t_vect center, float radius, t_color color);

t_plane *init_plane(t_vect point, t_vect normal, t_color color);

t_vect  get_intersection_point(t_ray ray, float t);

// Parsing

void			add_obj(int	type, t_objects **obj, char *line);
void			ambiant_parameter(char *line, t_objects *obj, t_objects **objects);
void			get_file(int fd, t_objects **obj);
void			get_line_parameter(char *line, t_objects **obj);
void			parsing(int fd, int ac, char **av, t_objects **obj);
void			obj_type(t_objects *obj, int type, char *line, t_objects **objects);
void			obj_type2(t_objects *obj, int type, char *line, t_objects **objects);
char			*get_blue(char *line, int i, t_objects **objects);
char			*get_green(char *line, int i, t_objects **objects);
char			*get_intensity(char *line, int i, t_objects **objects);
char			*get_red(char *line, int i, t_objects **objects);
int 			check_args(int ac, char **av);
int				ft_isfloat(char c);
int				get_id(char *line, t_objects **obj);
int				init_id(char *line, char *id, t_objects **obj);
int				is_rt(char *str);
int				str_big(char *str1, char *str2);
float			ft_atof(char *str);
unsigned int	ft_atoui(char *str);
t_color		get_colors(char *line, int i, t_objects **objects);
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
void	free_exit(t_objects **obj);
void	msg_free_exit(t_objects **obj, char *msg);
void	free_objects(t_objects **obj);

// Utils

float	ft_atof(char *str);

#endif