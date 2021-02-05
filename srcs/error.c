/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:27:26 by atourret          #+#    #+#             */
/*   Updated: 2021/02/05 15:59:22 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	free_data(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->s)
		free(data->s);
	if (data->line)
		free(data->line);
	if (data->map)
		free(data->map);
}

void	err(t_data *data, char *error, char c)
{
	if (c == 0)
		printf("\033[31m%s\n", error);
	else
		printf("\033[31m%s \033[33m%c\033[31m.\n", error, c);
	free_data(data);
	close(data->fd);
	exit(EXIT_FAILURE);
}
