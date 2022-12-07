/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:30 by marvin            #+#    #+#             */
/*   Updated: 2022/12/07 12:04:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane *init_plane(t_vect point, t_vect normal, t_color color)
{
    t_plane *ret;

    ret = malloc(sizeof(t_plane));
    if (!ret)
        return (NULL);
    ret->point = point;
    ret->normal = normal;
    ret->color = color;
    return (ret);
}