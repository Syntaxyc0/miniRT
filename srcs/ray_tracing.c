/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:02:45 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 13:10:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera_settings   init_settings(t_camera *cam)
{
    t_camera_settings ret;

    ret.ratio = WINDOW_WIDTH / WINDOW_HEIGHT;
    ret.forward = normalize_v(cam->orientation);
    ret.abs = normalize_v(vect_product(ret.forward, init_vect(0, 1.0, 0)));
    ret.ord = normalize_v(vect_product(ret.forward, ret.abs));
    ret.fov_ratio = tanf(cam->angle / 2 * M_PI / 180);
    return (ret);
}

t_vect  get_direction(t_camera_settings settings, int x, int y)
{
    float   x_proj;
    float   y_proj;

    x_proj = (2 * (x + 0.5) / WINDOW_WIDTH - 1) * settings.ratio * settings.fov_ratio;
    y_proj = (1 - 2 * (y + 0.5) / WINDOW_HEIGHT) * settings.fov_ratio;
    return (init_vect(x_proj, y_proj, 1.0));
}

t_ray   set_ray(t_camera *cam, t_camera_settings settings, int x, int y)
{
    t_vect  dir;
    t_vect  tmp;
    t_ray   ret;

    tmp = get_direction(settings, x, y);
    dir.x = settings.abs.x * tmp.x + settings.ord.x * tmp.y + settings.forward.x * tmp.z;
    dir.y = settings.abs.y * tmp.x + settings.ord.y * tmp.y + settings.forward.y * tmp.z;
    dir.z = settings.abs.z * tmp.x + settings.ord.z * tmp.y + settings.forward.z * tmp.z;
    dir = normalize_v(dir);
    ret = init_ray(cam->position, dir);
    return (ret);
}

void	get_intersect_ray(t_minirt *minirt, t_ray *ray)
{
	t_objects	*obj;
	float		t;

	t = 0;
	obj = minirt->objects;
	while (obj)
	{
		if (obj->type == 4)
		{
			if (intersphere((t_sphere *)obj->object, *ray, &t))
				get_intersection_sphere((t_sphere *)obj->object, ray, &t);
		}
		else if (obj->type == 5)
		{
			if (interplane((t_plane *)obj->object, *ray, &t))
				get_intersection_plane((t_plane *)obj->object, ray, &t);
		}
		else if (obj->type == 6)
		{
			if (intercylinder((t_cylinder *)obj->object, *ray, &t))
				get_intersect_cylinder((t_cylinder *)obj->object, ray, &t);
		}
		obj = obj->next;
	}
}

void    ray_tracing(t_minirt *mini)
{
    t_camera_settings   settings;
    t_ray   ray;
    int x;
    int y;

    settings = init_settings(mini->camera);
    y = 0;
    while (y < WINDOW_HEIGHT)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            ray = set_ray(mini->camera, settings, x, y);
            get_intersect_ray(mini, &ray);
            shadows(mini, ray);
			put_pixel(mini->img, x, y, ray.color);
            x++;
        }
        y++;
    }
}
