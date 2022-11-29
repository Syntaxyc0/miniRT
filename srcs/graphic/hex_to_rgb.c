#include "minirt.h"

t_color hex_to_rgb(unsigned int hex)
{
	t_color	ret;

	ret.red = (hex >> 16 & 255);
	ret.blue = (hex >> 8 & 255);
	ret.green = (hex & 255);
	return (ret);
}