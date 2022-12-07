/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:20 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:04:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img	*init_img(void)
{
	t_img	*ret;

	ret = malloc(sizeof(t_img));
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