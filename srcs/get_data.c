/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:05:11 by atourret          #+#    #+#             */
/*   Updated: 2021/02/05 15:35:33 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int		find_end(t_data *data)
{
	int	j;

	j = data->i;
	while (data->line[j] == '.' || data->line[j] == '/')
		j++;
	while (data->line[j] && data->line[j] != '\t' && data->line[j] != ' ')
		j++;
	return (j);
}

void	pre_treatment_bis(t_data *data, char c, int j)
{
	if (c == 'W')
	{
		data->we = ft_substr(data->line, data->i, j - data->i);
		data->f_we++;
	}
	else if (c == 'E')
	{
		data->ea = ft_substr(data->line, data->i, j - data->i);
		data->f_ea++;
	}
	else if (c == 'S' && data->sprite)
	{
		data->s = ft_substr(data->line, data->i, j - data->i);
		data->f_s++;
	}
	else if (c == 'F')
	{
		get_colors_f(data);
		data->f_f++;
	}
	else if (c == 'C')
	{
		get_colors_c(data);
		data->f_c++;
	}
}

void	verif_res(t_data *data)
{
	skip_whitespaces(data, 1);
	if (!ft_isdigit(data->line[data->i]))
		err(data, "Merci de correctement formater la resolution.", 0);
}

void	pre_treatment(t_data *data, char c)
{
	int	j;

	j = find_end(data);
	if (c == 'R')
	{
		verif_res(data);
		while (ft_isdigit(data->line[data->i]))
			data->length = data->length * 10 + data->line[data->i++] - 48;
		verif_res(data);
		while (ft_isdigit(data->line[data->i]))
			data->width = data->width * 10 + data->line[data->i++] - 48;
		data->f_r++;
	}
	else if (c == 'N')
	{
		data->no = ft_substr(data->line, data->i, j - data->i);
		data->f_no++;
	}
	else if (c == 'S' && !data->sprite)
	{
		data->so = ft_substr(data->line, data->i, j - data->i);
		data->f_so++;
	}
	else
		pre_treatment_bis(data, c, j);
}
