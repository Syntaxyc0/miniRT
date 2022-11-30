/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_coeff_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:10:03 by marvin            #+#    #+#             */
/*   Updated: 2022/11/30 09:10:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	apply_coeff(unsigned int color, float coeff)
{
	t_color	rgb;

	rgb = hex_to_rgb(color);
	rgb.red = rgb.red * coeff;
	rgb.green = rgb.green * coeff;
	rgb.blue = rgb.blue * coeff;
	return (rgb_to_hex(rgb));
}

unsigned int	apply_coeff_color(unsigned int color, t_color to_add, float coeff)
{
	t_color	rgb;

	rgb = hex_to_rgb(color);
	rgb.red = rgb.red * to_add.red * coeff;
	rgb.green = rgb.green * to_add.green * coeff;
	rgb.blue = rgb.blue * to_add.blue * coeff;
	return (rgb_to_hex(rgb));
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