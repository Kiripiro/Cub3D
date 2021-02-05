/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:53:25 by atourret          #+#    #+#             */
/*   Updated: 2021/02/05 15:21:05 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	init_bis(t_data *data)
{
	data->floor_r = 0;
	data->floor_g = 0;
	data->floor_b = 0;
	data->sky_r = 0;
	data->sky_g = 0;
	data->sky_b = 0;
}

void	init(t_data *data)
{
	data->length = 0;
	data->width = 0;
	data->f_r = 0;
	data->no = 0;
	data->f_no = 0;
	data->so = 0;
	data->f_so = 0;
	data->we = 0;
	data->f_we = 0;
	data->ea = 0;
	data->f_ea = 0;
	data->s = 0;
	data->f_s = 0;
	data->f_f = 0;
	data->f_c = 0;
	data->map = 0;
	data->line = 0;
	data->i = 0;
	data->len = 0;
	data->sprite = 0;
	data->nb_line = 0;
	init_bis(data);
}

int		main(int ac, char **av)
{
	t_data	data;
	if (ac != 2)
	{
		puts("Veuillez entrer un seul argument.");
		return (0);
	}
	else
	{
		init(&data);
		parsing(&data, av[1]);
	}
	free_data(&data);
	return (0);
}
