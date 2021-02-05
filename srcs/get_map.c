/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:33:14 by atourret          #+#    #+#             */
/*   Updated: 2021/02/05 15:30:37 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int		make_map(t_data *data, t_list *head)
{
	int		i;
	int		j;

	i = 0;
	if (!(data->map = (char **)malloc(sizeof(char *) * (data->nb_line + 1))))
		return (0);
	while (head)
	{
		j = 0;
		data->map[i] = head->content;
		while (data->map[i][j] == 32 || \
				data->map[i][j] == '0' || data->map[i][j] == '1' || \
				data->map[i][j] == '2' || data->map[i][j] == 'N' || \
			   	data->map[i][j] == 'E' || data->map[i][j] == 'S' || \
				data->map[i][j] == 'W')
			j++;
		if (data->map[i][j])
			err(data, "Caractere non reconnu dans la map:", data->map[i][j]);
		head = head->next;
		i++;
	}
	return (1);
}
