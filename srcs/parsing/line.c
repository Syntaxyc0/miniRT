/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:04:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:14:46 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_line_parameter(char *line, t_minirt *minirt, int line_nb)
{
	if (!get_id(line, minirt))
	{
		printf("l.%d : ", line_nb);
		msg_free_exit(minirt, ERR_ID);
	}
}

int	get_id(char *line, t_minirt *minirt)
{
	int		i;
	char	*id;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	id = malloc(i + 1);
	if (!id)
		return (0);
	i = -1;
	while (ft_isalpha(line[++i]))
		id[i] = line[i];
	id[i] = 0;
	if (minirt->id)
		free(minirt->id);
	minirt->id = id;
	if (!init_id(line, id, minirt))
		return (0);
	return (1);
}

int	init_id(char *line, char *id, t_minirt *minirt)
{
	if (!ft_strncmp(id, "A", str_big(id, "A")))
		add_obj(1, minirt, line);
	else if (!ft_strncmp(id, "C", str_big(id, "C")))
		add_obj(2, minirt, line);
	else if (!ft_strncmp(id, "L", str_big(id, "L")))
		add_obj(3, minirt, line);
	else if (!ft_strncmp(id, "sp", str_big(id, "sp")))
		add_obj(4, minirt, line);
	else if (!ft_strncmp(id, "pl", str_big(id, "pl")))
		add_obj(5, minirt, line);
	else if (!ft_strncmp(id, "cy", str_big(id, "cy")))
		add_obj(6, minirt, line);
	else
		return (0);
	return (1);
}
