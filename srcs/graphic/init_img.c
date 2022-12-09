#include "minirt.h"

t_image	*init_image(void)
{
	t_image	*ret;

	ret = malloc(sizeof(t_image));
	if (!ret)
		return (NULL);
	ret->mlx = NULL;
	ret->win = NULL;
	ret->img = NULL;
	ret->bits_per_pixel = 0;
	ret->line_len = 0;
	ret->endian = 0;
	return (ret);
}