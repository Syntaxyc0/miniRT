#include "minirt.h"

int main()
{
    t_vect a;
    t_vect b;

    a.x = 1;
    a.y = 2;
    a.z = 3;

    b.x = 1;
    b.y = 2;
    b.z = 3;
    printf("dot : %f\n", dot(a, b));
}