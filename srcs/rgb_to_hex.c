#include "minirt.h"

unsigned int	rgb_to_hex(t_color color)
{
	unsigned int	ret;

	ret = color.red << 16 | color.green << 8 | color.blue;
	return (ret);
}