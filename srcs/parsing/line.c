/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:04:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/15 14:02:22 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_line_parameter(char *line, t_objects **obj)
{
	if (!get_id(line, obj))
	{
		print_error(ERR_ID);
		return;
	}
	
}

int	get_id(char *line, t_objects **obj)
{
	int 	i;
	char	*id;

	j = 0;
	while (ft_isalpha(line[i]))
		i++;
	id = malloc(i + 1);
	if (!id)
		return (0);
	while (ft_isalpha(line[i]))
		id[i++] = line[i++];
	id[i++] = 0;
	check_id(id, obj);
}

void	check_id(char *id, t_objects **obj)
{
	if (!strncmp(id, "A", str_big(id, "A")))
		add_obj(1, obj);
	if (!strncmp(id, "C", str_big(id, "C")))
		add_obj(2, obj);
	if (!strncmp(id, "L", str_big(id, "L")))
		add_obj(3, obj);
	if (!strncmp(id, "sp", str_big(id, "sp")))
		add_obj(4, obj);
	if (!strncmp(id, "pl", str_big(id, "pl")))
		add_obj(5, obj);
	if (!strncmp(id, "cy", str_big(id, "cy")))
		add_obj(6, obj);
	else
		return ;
}
