/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:29:02 by atourret          #+#    #+#             */
/*   Updated: 2021/02/05 15:24:17 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int		check_line(t_data *data)
{
	int		i;

	i = 1;
	while (data->line[i] && (data->line[i] == 9 || data->line[i] == 32 || \
		data->line[i] == ',' || ft_isdigit(data->line[i])))
		i++;
	if (data->line[i])
		err(data, "Parametre(s) de couleur non valide:", data->line[i]);
	return (0);
}

int		get_colors_c(t_data *data)
{
	int		i;

	i = 1;
	check_line(data);	
	while (data->line[i] == 9 || data->line[i] == 32)
		i++;
	while (ft_isdigit(data->line[i]))
		data->sky_r = data->sky_r * 10 + data->line[i++] - 48;
	while (data->line[i] == 9 || data->line[i] == 32 || data->line[i] == ',')
		i++;
	while (ft_isdigit(data->line[i]))
		data->sky_g = data->sky_g * 10 + data->line[i++] - 48;
	while (data->line[i] == 9 || data->line[i] == 32 || data->line[i] == ',')
		i++;
	while (ft_isdigit(data->line[i]))
		data->sky_b = data->sky_b * 10 + data->line[i++] - 48;
	return (0);
}

int		get_colors_f(t_data *data)
{
	int		i;

	i = 1;
	check_line(data);
	while (data->line[i] == 9 || data->line[i] == 32)
		i++;
	while (ft_isdigit(data->line[i]))
		data->floor_r = data->floor_r * 10 + data->line[i++] - 48;
	while (data->line[i] == 9 || data->line[i] == 32 || data->line[i] == ',')
		i++;
	while (ft_isdigit(data->line[i]))
		data->floor_g = data->floor_g * 10 + data->line[i++] - 48;
	while (data->line[i] == 9 || data->line[i] == 32 || data->line[i] == ',')
		i++;
	while (ft_isdigit(data->line[i]))
		data->floor_b = data->floor_b * 10 + data->line[i++] - 48;
	return (0);
}
