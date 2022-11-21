/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:04:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/21 14:49:53 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_line_parameter(char *line, t_objects **obj)
{
	if (!get_id(line, obj))
		msg_free_exit(obj, ERR_ID);
}

int	get_id(char *line, t_objects **obj)
{
	int 	i;
	int		j;
	char	*id;

	i = 0;
	j = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isalpha(line[i]))
	{
		i++;
		j++;
	}
	id = malloc(j + 1);
	if (!id)
		return (0);
	i -= j;
	j = 0;
	while (ft_isalpha(line[i]))
		id[j++] = line[i++];
	id[j] = 0;
	if (!init_id(line, id, obj))
		return(0);
	return (1);
}

int	init_id(char *line, char *id, t_objects **obj)
{
	if (!ft_strncmp(id, "A", str_big(id, "A")))
		add_obj(1, obj, line);
	if (!ft_strncmp(id, "C", str_big(id, "C")))
		add_obj(2, obj, line);
	if (!ft_strncmp(id, "L", str_big(id, "L")))
		add_obj(3, obj, line);
	if (!ft_strncmp(id, "sp", str_big(id, "sp")))
		add_obj(4, obj, line);
	if (!ft_strncmp(id, "pl", str_big(id, "pl")))
		add_obj(5, obj, line);
	if (!ft_strncmp(id, "cy", str_big(id, "cy")))
		add_obj(6, obj, line);
	else
		return (0);
	return (1);
}
