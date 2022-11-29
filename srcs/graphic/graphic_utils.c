#include "minirt.h"

void	set_img(t_minirt *mini)
{
	t_img *img;

	img = mini->img;
	img->mlx = mlx_init();
	if (!img->mlx)
		return ; // gestion d'erreur free_minirt exit
	mimg->win = mlx_new_window(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Minirt");
	if (!img->win)
		return ; // gestion d'erreur free_minirt exit
	img->img = mlx_new_image(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_len, &img->endian);
}

void	put_pixel(t_img	*img, int x, int y, unsigned int color)
{
	char	*addr;

	addr = img->addr + x * (img->bits_per_pixel / 8) + y * img->line_len;
	*(unsigned int *)addr = color;
}

void	display_img(t_img	*img)
{
	mlx_put_img_to_window(img->mlx, img->win, img->img, 0, 0);
}