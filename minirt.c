/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:05:14 by marvin            #+#    #+#             */
/*   Updated: 2022/12/12 16:34:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minirt	*minirt;
	int			fd;

	fd = 0;
	minirt = init_minirt();
	parsing(fd, argc, argv, minirt);
	minirt->img = init_img();
	if (!minirt->img)
		msg_free_exit(minirt, ERR_MALLOC);
	set_img(minirt);
	ray_tracing(minirt);
	display_img(minirt->img);
	loop(minirt);
	free_minirt(minirt);
}
