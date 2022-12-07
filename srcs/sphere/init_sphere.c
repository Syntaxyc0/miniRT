/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:37 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:04:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere    *init_sphere(t_vect center, float radius, t_color color)
{
    t_sphere    *ret;

    ret = malloc(sizeof(t_sphere));
    if (!ret)
        return (NULL);
    ret->center = center;
    ret->radius = radius;
    ret->color.red = color.red;
    ret->color.green = color.green;
    ret->color.blue = color.blue;
    return (ret);
}