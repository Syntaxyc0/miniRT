/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:53 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:04:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect  substract_v(t_vect a, t_vect b)
{
    t_vect  ret;

    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    ret.z = a.z - b.z;
    return (ret);
}

t_vect  mult_v(t_vect a, float t)
{
    t_vect  ret;

    ret.x = a.x * t;
    ret.y = a.y * t;
    ret.z = a.z * t;
    return (ret);
}

t_vect  add_v(t_vect a, t_vect b)
{
    t_vect  ret;

    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    ret.z = a.z + b.z;
    return (ret);
}

float  norm_v(t_vect a)
{
    return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vect  normalize_v(t_vect a)
{
    t_vect ret;

    ret.x = a.x / norm_v(a);
    ret.y = a.y / norm_v(a);
    ret.z = a.z / norm_v(a);

    return (ret);
}