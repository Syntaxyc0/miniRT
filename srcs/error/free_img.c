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
		free(minirt->img->mlx);
	if (minirt->img->win)
		free(minirt->img->win);
	if (minirt->img->img)
		free(minirt->img->img);
	free(minirt->img);
}
