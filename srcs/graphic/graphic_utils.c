/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:11 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 16:22:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_img(t_minirt *mini)
{
	t_image	*img;

	img = mini->img;
	img->mlx = mlx_init();
	if (!img->mlx)
		msg_free_exit(mini, ERR_INIT);
	img->win = mlx_new_window(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Minirt");
	if (!img->win)
		msg_free_exit(mini, ERR_WIN);
	img->img = mlx_new_image(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_len, &img->endian);
}

void	put_pixel(t_image	*img, int x, int y, unsigned int color)
{
	char	*addr;

	addr = img->addr + x * (img->bits_per_pixel / 8) + y * img->line_len;
	*(unsigned int *)addr = color;
}

void	display_img(t_image	*img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

t_color	init_white(void)
{
	t_color			white;

	white.red = 255;
	white.blue = 255;
	white.green = 255;
	return (white);
}

t_color	init_black(void)
{
	t_color			black;

	black.red = 0;
	black.blue = 0;
	black.green = 0;
	return (black);
}
