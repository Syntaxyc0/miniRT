#include "minirt.h"

// int main(int argc, char **argv)
// {
//     t_vect a;
//     t_vect b;
//     t_vect result;

//     (void)argc;
//     a.x = atof(argv[1]);
//     a.y = atof(argv[2]);
//     a.z = atof(argv[3]);

//     b.x = atof(argv[4]);
//     b.y = atof(argv[5]);
//     b.z = atof(argv[6]);
//     result = vect_product(a, b);
//     printf("produit vectoriel\nres x : %f\nret y : %f\nres z : %f\n", result.x, result.y, result.z);
// }

// int main(int argc, char **argv)
// {
//     t_vect a;

//     (void)argc;
//     a.x = atof(argv[1]);
//     a.y = atof(argv[2]);
//     a.z = atof(argv[3]);

//     printf("norme a : %f\n", norm_v(a));
// }

// int main(int argc, char **argv)
// {
//     t_vect a;
//     t_vect b;
//     t_vect result;

//     (void)argc;
//     a.x = atof(argv[1]);
//     a.y = atof(argv[2]);
//     a.z = atof(argv[3]);

//     b.x = atof(argv[4]);
//     b.y = atof(argv[5]);
//     b.z = atof(argv[6]);
//     result = add_v(a, b);
//     printf("add \nres x : %f\nret y : %f\nres z : %f\n", result.x, result.y, result.z);
// }

// int main(int argc, char **argv)
// {
//     t_vect a;
//     t_vect b;
//     t_vect origin;
//     t_ray   ray;
//     float result;
//     t_sphere *sphere;
//     t_color color;

//     color.red = 0;
//     color.green = 0;
//     color.blue = 0;
    
//     (void)argc;
//     a.x = atof(argv[1]);
//     a.y = atof(argv[2]);
//     a.z = atof(argv[3]);

//     b.x = atof(argv[4]);
//     b.y = atof(argv[5]);
//     b.z = atof(argv[6]);

//     origin.x = atof(argv[7]);
//     origin.y = atof(argv[8]);
//     origin.z = atof(argv[9]);

// 	float radius = atof(argv[10]); 

//     ray.start = a;
//     ray.dir = b;
//     sphere = init_sphere(origin, radius, color);
//     if (!intersphere(sphere, ray, &result))
//         return (1);
//     printf("result %f\n", result);
//     t_vect  inter;
//     inter = get_intersection_point(ray, result);
//     printf("coord intersection point : %f %f %f\n", inter.x, inter.y, inter.z);
// }

// int main()
// {
// 	t_color color;
// 	color.red=250;
// 	color.blue=250;
// 	color.green=250;
// 	printf("hex value : 0x%06x\n", rgb_to_hex(color));
// }

// int main()
// {
// 	t_color color;
// 	color.red = 255;
// 	color.blue = 255;
// 	color.green = 255;
// 	t_cylinder *cylinder;
// 	t_vect a = init_vect(0,0,0);
// 	float t = 0;
// 	t_ray ray = init_ray(a, a);
// 	cylinder = init_cylinder(a, a, 25, 15, color);
// 	t_plane *plane = (t_plane *)cylinder;
// 	printf("0x%06x\n", rgb_to_hex(plane->color));
// 	inter_cylinder_bot(cylinder, &ray, &t);
// }

// int main() // DIST OK
// {
// 	t_vect a;
// 	t_vect b;

// 	a.x = 12.4564;
// 	a.y = -0.574;
// 	a.z = 0.345;

// 	b.x = 45.9545;
// 	b.y = 45.9545;
// 	b.z = 45.9545;
// 	printf("dist : %f\n", compute_dist(a, b));
// }

// int main(int argc, char **argv)
// {
//     t_vect a;
//     t_vect b;
//     t_vect origin;
// 	t_vect	normal;
//     t_ray   ray;
// 	t_cylinder	*cylinder;
//     float result;
//     t_color color;

//     color.red = 0;
//     color.green = 0;
//     color.blue = 0;
    
//     (void)argc;
//     a.x = atof(argv[1]);
//     a.y = atof(argv[2]);
//     a.z = atof(argv[3]);

//     b.x = atof(argv[4]);
//     b.y = atof(argv[5]);
//     b.z = atof(argv[6]);

//     origin.x = atof(argv[7]);
//     origin.y = atof(argv[8]);
//     origin.z = atof(argv[9]);

//     normal.x = atof(argv[10]);
//     normal.y = atof(argv[11]);
//     normal.z = atof(argv[12]);

// 	float	diameter = atof(argv[13]);
// 	float	height = atof(argv[14]);

//     ray.start = a;
//     ray.dir = b;
//     cylinder = init_cylinder(origin, normal, diameter, height, color);
//     if (!intercylinder(cylinder, ray, &result))
//         return (1);
//     printf("result %f\n", result);
//     t_vect  inter;
//     inter = get_intersection_point(ray, result);
//     printf("coord intersection point : %f %f %f\n", inter.x, inter.y, inter.z);
// }

int main(int argc, char **argv) // INTERSECTION RAY/PLANE OK
{
    t_vect a;
    t_vect b;
    t_vect origin;
	t_vect	normal;
    t_ray   ray;
    float result;
    t_plane *plane;
    t_color color;

    color.red = 254;
    color.green = 254;
    color.blue = 254;
    
    (void)argc;
    a.x = atof(argv[1]);
    a.y = atof(argv[2]);
    a.z = atof(argv[3]);

    b.x = atof(argv[4]);
    b.y = atof(argv[5]);
    b.z = atof(argv[6]);

    origin.x = atof(argv[7]);
    origin.y = atof(argv[8]);
    origin.z = atof(argv[9]);

    normal.x = atof(argv[10]);
    normal.y = atof(argv[11]);
    normal.z = atof(argv[12]);

    ray = init_ray(a, b);
    plane = init_plane(origin, normal, color);
    if (!interplane(plane, ray, &result))
	{
        return (1);
	}
	get_intersecton_plane(plane, &ray, &result);
    printf("coord intersection point : %f %f %f\n", ray.inter.x, ray.inter.y, ray.inter.z);
	printf("distance %f\n", ray.inter_distance);
	printf("ray color : 0x%06x\n", ray.color);
	printf("ray_len : %f\n", norm_v(substract_v(ray.inter, ray.start)));
}

// int main(int argc, char **argv)
// {
//     t_vect a;
//     t_vect result;

//     (void)argc;
//     a.x = atof(argv[1]);
//     a.y = atof(argv[2]);
//     a.z = atof(argv[3]);

//     result = normalize_v(a);
//     printf("res x : %f\nret y : %f\nres z : %f\n", result.x, result.y, result.z);
// }

// int main()
// {
//     t_vect a;
//     t_vect b;

//     a.x = 2;
//     a.y = 2;
//     a.z = 2;

//     b.x = 3;
//     b.y = 3;
//     b.z = 3;
//     printf("dot : %f\n", dot(a, b));
// }