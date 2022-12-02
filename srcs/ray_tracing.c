#include "minirt.h"

t_camera_settings   init_settings(t_camera *cam)
{
    t_camera_settings ret;
    float   ratio;

    ratio = WINDOW_WIDTH / WINDOW_HEIGHT;
    ret.forward = normalize_v(cam->orientation);
    ret.abs = normalize_v(vect_product(ret.forward, init_vect(0, 1.0, 0)));
    ret.ord = normalize_v(vect_product(ret.forward, ret.abs));
    ret.width = 2 * tanf(cam->angle / 2 * M_PI / 180);
    ret.height = width / ratio;
    return (ret);
}

t_ray   set_ray(t_camera *cam, t_camera_settings settings, int x_proj, int y_proj)
{
    t_vect  dir;
    t_vect  tmp;
    t_ray   ret;

    tmp = init_vect(x_proj * settings.width / WINDOW_WIDTH, y_proj * settings.height / WINDOW_HEIGHT, 1.0);
    dir.x = settings.abs.x * tmp.x + settings.ord.x * tmp.y + settings.forward.x * tmp.z;
    dir.y = settings.abs.y * tmp.x + settings.ord.y * tmp.y + settings.forward.y * tmp.z;
    dir.z = settings.abs.z * tmp.x + settings.ord.z * tmp.y + settings.forward.z * tmp.z;
    dir = normalize_v(dir);
    ret = init_ray(cam->position, dir);
    return (ret);
}

void    ray_tracing(t_minirt *mini)
{
    t_camera_settings   settings;
    t_ray   ray;
    int x;
    int y;
    int   x_proj;
    int   y_proj;

    settings = init_settings(mini->camera);
    y = 0;
    y_proj = WINDOW_HEIGHT / 2;
    while (y_proj >= -WINDOW_HEIGHT / 2)
    {
        x = 0;
        x_proj = -WINDOW_WIDTH / 2;
        while (x_proj <= WINDOW_WIDTH / 2)
        {
            ray = set_ray(mini->camera, settings, x_proj, y_proj);
        }
    }


}