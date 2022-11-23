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


//     ray.start = a;
//     ray.dir = b;
//     sphere = init_sphere(origin, 2.0, color);
//     if (!intersphere(sphere, ray, &result))
//         return (1);
//     printf("result %f\n", result);
//     t_vect  inter;
//     inter = get_intersection_point(ray, result);
//     printf("coord intersection point : %f %f %f\n", inter.x, inter.y, inter.z);
// }

int main(int argc, char **argv)
{
	t_minirt	*minirt;
	t_sphere	*sp;
	int 	fd;

	fd = 0;
	minirt = init_minirt();
    parsing(fd, argc, argv, minirt);
	printf("A : intensity = %f color = %u,%u,%u\n", minirt->ambiant->intensity,
			minirt->ambiant->color.red, minirt->ambiant->color.green, minirt->ambiant->color.blue);
	printf("C : position = %f,%f,%f orientation = %f,%f,%f angle = %f\n",
			minirt->camera->position.x, minirt->camera->position.y, minirt->camera->position.z,
			minirt->camera->orientation.x, minirt->camera->orientation.y, minirt->camera->orientation.z, 
			minirt->camera->angle);
	printf("L : position = %f,%f,%f intensity = %f\n",
			minirt->light->position.x, minirt->light->position.y, minirt->light->position.z,
			minirt->light->intensity);

	sp = (t_sphere*)minirt->objects->object;
	printf("sp : center = %f,%f,%f diameter = %f color = %u,%u,%u\n",
		sp->center.x, sp->center.y, sp->center.z,
		sp->radius,
		sp->color.red, sp->color.green, sp->color.blue);
}

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