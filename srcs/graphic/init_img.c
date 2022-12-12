/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:20 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 15:47:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_image	*init_img(void)
{
	t_image	*ret;

	ret = malloc(sizeof(t_image));
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
