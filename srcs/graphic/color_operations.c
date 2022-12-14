/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:03:59 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:03:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	apply_coeff(t_color color, double coeff)
{
	t_color	ret;

	ret.red = color.red * coeff;
	ret.green = color.green * coeff;
	ret.blue = color.blue * coeff;
	return (ret);
}

t_color	apply_coeff_color(t_color color, t_color add, double coeff)
{
	t_color	ret;

	ret.red = color.red * add.red * coeff / 255;
	ret.green = color.green * add.green * coeff / 255;
	ret.blue = color.blue * add.blue * coeff / 255;
	return (ret);
}

unsigned int	add_color(unsigned int color, unsigned int to_add)
{
	t_color	color1;
	t_color	color2;
	t_color	result;

	color1 = hex_to_rgb(color);
	color2 = hex_to_rgb(to_add);
	result.red = color1.red + color2.red;
	result.green = color1.green + color2.green;
	result.blue = color1.blue + color2.blue;
	if (result.red > 255)
		result.red = 255;
	if (result.green > 255)
		result.green = 255;
	if (result.blue > 255)
		result.blue = 255;
	return (rgb_to_hex(result));
}

t_color	add_color_v(t_color color1, t_color color2)
{
	t_color	result;

	result.red = color1.red + color2.red;
	result.green = color1.green + color2.green;
	result.blue = color1.blue + color2.blue;
	if (result.red > 255)
		result.red = 255;
	if (result.green > 255)
		result.green = 255;
	if (result.blue > 255)
		result.blue = 255;
	return (result);
}

t_color	add_color_coeff(t_color color1, t_color color2, double coeff)
{
	t_color	result;

	result.red = color1.red * color2.red * coeff / 255.0;
	result.green = color1.green * color2.green * coeff / 255.0;
	result.blue = color1.blue * color2.blue * coeff / 255.0;
	if (result.red > 255)
		result.red = 255;
	if (result.green > 255)
		result.green = 255;
	if (result.blue > 255)
		result.blue = 255;
	return (result);
}
