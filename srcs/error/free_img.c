/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:02:41 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:02:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_img(t_minirt *minirt)
{
	if (minirt->img->mlx)
	{
		if (minirt->img->win)
			mlx_destroy_window(minirt->img->mlx, minirt->img->win);
		if (minirt->img->img)
			mlx_destroy_image(minirt->img->mlx, minirt->img->img);
		mlx_destroy_display(minirt->img->mlx);
		free(minirt->img->mlx);
	}
	free(minirt->img);
}
