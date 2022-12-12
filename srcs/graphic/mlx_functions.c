/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:23:57 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 13:23:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	esc_button(int keycode, t_minirt *minirt)
{
	if (keycode == 65307)
	{
		free_minirt(minirt);
		exit(0);
	}
	return (0);
}

int	cross(t_minirt *minirt)
{
	free_minirt(minirt);
	exit (0);
	return (0);
}

void	loop(t_minirt *minirt)
{
	mlx_hook(minirt->img->win, 17, 0, cross, minirt);
	mlx_key_hook(minirt->img->win, esc_button, minirt);
	mlx_loop(minirt->img->mlx);
}
