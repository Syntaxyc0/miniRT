/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:04:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/16 14:31:08 by ggobert          ###   ########.fr       */
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

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	id = malloc(i + 1);
	if (!id)
		return (0);
	while (ft_isalpha(line[i]))
		id[i++] = line[i++];
	id[i++] = 0;
	init_id(line, id, obj);
	if (!id)
		return(0);
	return (1);
}

void	init_id(char *line, char *id, t_objects **obj)
{
	if (!strncmp(id, "A", str_big(id, "A")))
		add_obj(1, obj, line);
	if (!strncmp(id, "C", str_big(id, "C")))
		add_obj(2, obj, line);
	if (!strncmp(id, "L", str_big(id, "L")))
		add_obj(3, obj, line);
	if (!strncmp(id, "sp", str_big(id, "sp")))
		add_obj(4, obj, line);
	if (!strncmp(id, "pl", str_big(id, "pl")))
		add_obj(5, obj, line);
	if (!strncmp(id, "cy", str_big(id, "cy")))
		add_obj(6, obj, line);
	else
	{
		free(id);
		id = 0;
		return ;
	}
}
