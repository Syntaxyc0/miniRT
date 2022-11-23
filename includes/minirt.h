/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:47:30 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/23 15:58:11 by ggobert          ###   ########.fr       */
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
# define ERR_DOUBLE_A "ambiant light has to be defined once"
# define ERR_CONFORM_A "value(s) missing or not conform for ambiant light (A)"
# define ERR_INTENSITY_A "intensity value of ambiant light not in range [0,1]"
# define ERR_DOUBLE_C "camera has to be defined once"
# define ERR_CONFORM_C "value(s) missing or not conform for camera (C)"
# define ERR_ORIENT_C "orientation value(s) of camera not in range [-1,1]"
# define ERR_FOV_C "FOV value(s) of camera not in range [-1,1]"
# define ERR_DOUBLE_L "light has to be defined once"
# define ERR_CONFORM_L "value(s) missing or not conform for light (L)"
# define ERR_INTENSITY_L "intensity value of light not in range [0,1]"
# define ERR_CONFORM_SP "value(s) missing or not conform for sphere (sp)"

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
}	t_objects;

typedef struct	s_minirt
{
	t_ambiant	*ambiant;
	t_camera	*camera;
	t_light		*light;
	t_objects	*objects;
}	t_minirt;

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

void		add_obj(int	type, t_minirt *minirt, char *line);
void		ambiant_parameter(char *line, t_minirt *minirt);
void		camera_parameter(char *line, t_minirt *minirt);
void		get_file(int fd, t_minirt *minirt);
void		get_line_parameter(char *line, t_minirt *minirt);
void		light_parameter(char *line, t_minirt *minirt);
void		parsing(int fd, int ac, char **av, t_minirt *minirt);
void		obj_type(t_minirt *minirt, int type, char *line, t_objects *objects);
void		obj_type2(t_minirt *minirt, int type, char *line, t_objects *objects);
void		sphere_parameter(char *line, t_minirt *minirt, t_objects *obj);
char		*get_float(char *line, int i, t_minirt *minirt);
char		*get_red(char *line, int i, t_minirt *minirt);
char		*get_green(char *line, int i, t_minirt *minirt);
char		*get_blue(char *line, int i, t_minirt *minirt);
char		*get_x(char *line, int i, t_minirt *minirt);
char		*get_y(char *line, int i, t_minirt *minirt);
char		*get_z(char *line, int i, t_minirt *minirt);
int			ambiant_check_line(char *line, int i);
int			camera_check_line(char *line, int i);
int 		check_args(int ac, char **av);
int			check_vector(char *line, int i);
int			check_color(char *line, int i);
int			check_space(char *line, int i);
int			check_float(char *line, int i);
int			check_digit(char *line, int i);
int 		check_eof(char *line, int i);
int			get_id(char *line, t_minirt *minirt);
int			init_id(char *line, char *id, t_minirt *minirt);
int			is_rt(char *str);
int			light_check_line(char *line, int i);
int			range_float(float x, float min, float max);
int			range_vector(t_vect vect, float min, float max);
int			sphere_check_line(char *line, int i);
t_minirt	*init_minirt(void);
t_ambiant	*new_ambiant(void);
t_camera	*new_camera(void);
t_light		*new_light(void);
t_objects	*new_struct_objects(void);
t_objects	*last_obj(t_objects *obj);
t_sphere	*new_sphere(void);
t_plane		*new_plane(void);
t_cylinder	*new_cylinder(void);
t_color		get_colors(char *line, int i, t_minirt *minirt);
t_vect		get_vector(char *line, int i, t_minirt *minirt);

// Error

void	print_error(char *msg);
void	free_exit(t_minirt *minirt);
void	msg_free_exit(t_minirt *minirt, char *msg);
void	msg_free_line_exit(t_minirt *minirt, char *line, char *msg);
void	free_minirt(t_minirt *minirt);

// Utils

int				ft_isfloat(char c);
int				str_big(char *str1, char *str2);
float			ft_atof(char *str);
unsigned int	ft_atoui(char *str);

#endif

// !! Note : normalize vecteur normal