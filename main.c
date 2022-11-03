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
//     printf("res x : %f\nret y : %f\nres z : %f\n", result.x, result.y, result.z);
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
//     printf("res x : %f\nret y : %f\nres z : %f\n", result.x, result.y, result.z);
// }

int main(int argc, char **argv)
{
    t_vect a;
    t_vect result;

    (void)argc;
    a.x = atof(argv[1]);
    a.y = atof(argv[2]);
    a.z = atof(argv[3]);

    result = normalize_v(a);
    printf("res x : %f\nret y : %f\nres z : %f\n", result.x, result.y, result.z);
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