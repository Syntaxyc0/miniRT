/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:47:30 by ggobert           #+#    #+#             */
/*   Updated: 2022/12/12 16:39:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <X11/X.h>

# define ERR_NBARGS "wrong number of args"
# define ERR_TYPEARG "must be a .rt"
# define ERR_MALLOC "malloc failed"
# define ERR_ID "id unknown"
# define ERR_COLOR "wrong value of color"
# define ERR_double_A "ambiant light has to be defined once"
# define ERR_CONFORM_A "value(s) missing or not conform for ambiant light (A)"
# define ERR_INTENSITY_A "intensity value of ambiant light not in range [0,1]"
# define ERR_double_C "camera has to be defined once"
# define ERR_CONFORM_C "value(s) missing or not conform for camera (C)"
# define ERR_ORIENT_C "orientation value(s) of camera not in range [-1,1]"
# define ERR_FOV_C "FOV value(s) of camera not in range [-1,1]"
# define ERR_double_L "light has to be defined once"
# define ERR_CONFORM_L "value(s) missing or not conform for light (L)"
# define ERR_INTENSITY_L "intensity value of light not in range [0,1]"
# define ERR_CONFORM_SP "value(s) missing or not conform for sphere (sp)"
# define ERR_CONFORM_PL "value(s) missing or not conform for plane (pl)"
# define ERR_ORIENT_PL "orientation value(s) of plane not in range [-1,1]"
# define ERR_CONFORM_CY "value(s) missing or not conform for cylinder (cy)"
# define ERR_ORIENT_CY "orientation value(s) of cylinder not in range [-1,1]"
# define ERR_MISSCAM "need a camera in file"
# define ERR_INIT	"mlx_init failed"
# define ERR_WIN	"mlx_new_window failed"

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

# define EPS 1e-8

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}	t_vect;

typedef struct s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_color;

typedef struct s_ray
{
	t_vect			start;
	t_vect			dir;
	t_vect			inter;
	t_vect			normal;
	double			inter_distance;
	t_color	color;
}	t_ray;

typedef struct s_ambiant
{
	double	intensity;
	t_color	color;
}	t_ambiant;

typedef struct s_camera
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
	t_vect	center;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vect	point;
	t_vect	normal;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vect	point;
	t_vect	normal;
	t_color	color;
	double	diameter;
	double	height;
}	t_cylinder;

typedef struct s_objects
{
	int					type;
	void				*object;
	struct s_objects	*next;
}	t_objects;

typedef struct s_image
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_camera_settings
{
	t_vect	forward;
	t_vect	abs;
	t_vect	ord;	
	double	ratio;
	double	fov_ratio;
}	t_camera_settings;

typedef struct s_res
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_res;

typedef struct s_minirt
{
	t_ambiant	*ambiant;
	t_camera	*camera;
	t_light		*light;
	t_objects	*objects;
	t_image		*img;
	char		*id;
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

double			dot(t_vect a, t_vect b);
t_vect			add_v(t_vect a, t_vect b);
t_vect			substract_v(t_vect a, t_vect b);
t_vect			mult_v(t_vect a, double t);
double			norm_v(t_vect a);
t_vect			vect_product(t_vect a, t_vect b);
t_vect			normalize_v(t_vect a);
t_vect			init_vect(double x, double y, double z);
double			compute_dist(t_vect a, t_vect b);

int				intersphere(t_sphere *sphere, t_ray ray, double *t);
int				get_intersection_sphere(t_sphere *sphere, t_ray *ray, double *t);

int				interplane(t_plane *plane, t_ray ray, double *t);
int				get_intersection_plane(t_plane *plane, t_ray *ray, double *t);

int				inter_cylinder_bot(t_cylinder *cyl, t_ray *ray, double *t);
void			get_intersection_bot_point(t_cylinder *cyl,
					t_ray *ray, double *t);
int				inter_cylinder_top(t_cylinder *cyl, t_ray *ray, double *t);
void			get_intersection_top_point(t_cylinder *cyl,
					t_ray *ray, double *t);
void			get_intersect_cylinder(t_cylinder *cyl, t_ray *ray, double *t);
int				inter_cylinder_pipe(t_cylinder *cyl, t_ray *ray, double *t);
void			get_intersection_cylinder_pipe(t_cylinder *cyl, t_ray *ray, double *t);


void			ray_tracing(t_minirt *mini);
t_color	shadows(t_minirt *mini, t_ray *ray);

t_ray			init_ray(t_vect	origin, t_vect direction);
t_vect			get_intersection_point(t_ray ray, double t);
int				solve_quadratic_equation(double a, double b, double c, double *t);

t_image			*init_img(void);
unsigned int	rgb_to_hex(t_color color);
t_color	apply_coeff(t_color color, double coeff);
t_color	apply_coeff_color(t_color color,
					t_color to_add, double coeff);
t_color	add_color_v(t_color color,
					t_color to_add);
t_color			hex_to_rgb(unsigned int hex);
void			set_img(t_minirt *mini);
void			put_pixel(t_image	*img, int x, int y, unsigned int color);
t_color			init_white(void);
t_color			init_black(void);
t_color			mix_colors(t_color color, t_color add, double coeff);
void			display_img(t_image	*img);
void			loop(t_minirt *minirt);

// Parsing

void			add_obj(int type, t_minirt *minirt, char *line);
void			ambiant_parameter(char *line, t_minirt *minirt);
void			camera_parameter(char *line, t_minirt *minirt);
void			cylinder_parameter(char *line, t_minirt *minirt,
					t_objects *obj);
void			get_file(int fd, t_minirt *minirt);
void			get_line_parameter(char *line, t_minirt *minirt, int line_nb);
void			light_parameter(char *line, t_minirt *minirt);
void			parsing(int fd, int ac, char **av, t_minirt *minirt);
void			obj_type(t_minirt *minirt, int type, char *line,
					t_objects *objects);
void			obj_type2(t_minirt *minirt, int type, char *line,
					t_objects *objects);
void			obj_type3(t_minirt *minirt, int type, char *line,
					t_objects *obj);
void			plane_parameter(char *line, t_minirt *minirt, t_objects *obj);
void			sphere_parameter(char *line, t_minirt *minirt, t_objects *obj);
char			*get_double(char *line, int i, t_minirt *minirt);
char			*get_red(char *line, int i, t_minirt *minirt);
char			*get_green(char *line, int i, t_minirt *minirt);
char			*get_blue(char *line, int i, t_minirt *minirt);
char			*get_x(char *line, int i, t_minirt *minirt);
char			*get_y(char *line, int i, t_minirt *minirt);
char			*get_z(char *line, int i, t_minirt *minirt);
int				ambiant_check_line(char *line, int i);
int				camera_check_line(char *line, int i);
int				cylinder_check_line(char *line, int i);
int				cylinder_check_line2(char *line, int i);
int				check_args(int ac, char **av);
int				check_vector(char *line, int i);
int				check_color(char *line, int i);
int				check_space(char *line, int i);
int				check_double(char *line, int i);
int				check_digit(char *line, int i);
int				check_eof(char *line, int i);
int				get_id(char *line, t_minirt *minirt);
int				init_id(char *line, char *id, t_minirt *minirt);
int				is_rt(char *str);
int				light_check_line(char *line, int i);
int				next_value(char *line, int i);
int				plane_check_line(char *line, int i);
int				range_double(double x, double min, double max);
int				range_vector(t_vect vect, double min, double max);
int				sphere_check_line(char *line, int i);
t_minirt		*init_minirt(void);
t_ambiant		*new_ambiant(void);
t_camera		*new_camera(void);
t_light			*new_light(void);
t_objects		*new_struct_objects(void);
t_objects		*last_obj(t_objects *obj);
t_sphere		*new_sphere(void);
t_plane			*new_plane(void);
t_cylinder		*new_cylinder(void);
t_color			get_colors(char *line, int i, t_minirt *minirt);
t_vect			get_vector(char *line, int i, t_minirt *minirt);

// Error

void			print_error(char *msg);
void			free_exit(t_minirt *minirt);
void			msg_free_exit(t_minirt *minirt, char *msg);
void			msg_free_line_exit(t_minirt *minirt, char *line, char *msg);
void			free_minirt(t_minirt *minirt);
void			free_img(t_minirt *minirt);

// Utils

int				ft_isdouble(char c);
int				str_big(char *str1, char *str2);
double			ft_atof(char *str);
unsigned int	ft_atoui(char *str);
void			display_vect(t_vect	vect);

#endif

// !! Note : normalize vecteur normal
