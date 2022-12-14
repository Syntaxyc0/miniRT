/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:46 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 16:28:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	init_vect(double x, double y, double z)
{
	t_vect	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}
