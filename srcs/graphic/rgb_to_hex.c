/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:25 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:04:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	rgb_to_hex(t_color color)
{
	unsigned int	ret;

	ret = color.red << 16 | color.green << 8 | color.blue;
	return (ret);
}
