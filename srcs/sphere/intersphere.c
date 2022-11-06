#include "minirt.h"

int solve_equation(double a, double b, double c, double *t)
{
    double  delta;
    double  r0;
    double  r1;

    delta = b * b - 4.0 * a * c;
    if (delta < 0)
        return (0);
    else if (delta == 0)
        *t = -1 * b / (2 * a);
    else
    {
        r0 = (-1 * b - sqrt(delta)) / (2 * a);
        printf("r0 : %f\n", r0);
        r1 = (-1 * b + sqrt(delta)) / (2 * a);
        printf("r1 : %f\n", r1);
        if (r0 <= 0 || r1 <= 0)
            return(0);
        if (r0 < r1)
            *t = r0;
        else
            *t = r1;
    }
    return (1);
}

int intersphere(t_sphere *sphere, t_ray ray, double *t)
{
    double  a;
    double  b;
    double  c;

    a = dot(ray.dir, ray.dir);
    b = 2.0 * dot(ray.dir, substract_v(ray.start, sphere->center));
    c = dot(substract_v(ray.start, sphere->center), substract_v(ray.start, sphere->center)) - sphere->radius * sphere->radius;
    if (solve_equation(a, b, c, t))
        return (1);
    return (0);
}