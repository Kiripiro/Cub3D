/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:33:14 by atourret          #+#    #+#             */
/*   Updated: 2021/02/05 18:00:27 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	clean_map(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_ischar("012", data->map[y][x]))
				data->map[y][x] = ' ';
			x++;
		}
		y++;
	}
}

void    flood_fill(t_data *data, int i, int n)
{
    if (i < 0 || n < 0 || i > (data->nb_line - 1) || \
        n > (ft_strlen(data->map[i]) - 1))
        err(data, "La map n'est pas valide.", 0);
    if (ft_ischar("|.?" ,data->map[i][n]))
        return ;
    if (data->map[i][n] == '1')
    {
        data->map[i][n] = '|';
        return ;
    }
    if (data->map[i][n] == '0')
        data->map[i][n] = '.';
    if (data->map[i][n] == '2')
        data->map[i][n] = '$';
    flood_fill(data, i - 1, n);
    flood_fill(data, i + 1, n);
    flood_fill(data, i, n - 1);
    flood_fill(data, i, n + 1);
}

void	find_spawn(t_data *data, char c, int y, int x)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
	{
		if (!data->y && !data->x)
		{
			data->y = y;
			data->x = x;
		}
		else
			err(data, "Merci de ne mettre qu'un seul point de spawn.", c);
	}
}

int		make_map(t_data *data, t_list *head)
{
	int		y;
	int		x;

	y = 0;
	if (!(data->map = (char **)malloc(sizeof(char *) * (data->nb_line + 1))))
		return (0);
	while (head)
	{
		x = 0;
		data->map[y] = head->content;
		while (data->map[y][x] == 32 || \
				data->map[y][x] == '0' || data->map[y][x] == '1' || \
				data->map[y][x] == '2' || data->map[y][x] == 'N' || \
				data->map[y][x] == 'E' || data->map[y][x] == 'S' || \
				data->map[y][x] == 'W')
		{
			find_spawn(data, data->map[y][x], y, x);
			x++;
		}
		if (data->map[y][x])
			err(data, "Caractere non reconnu dans la map:", data->map[y][x]);
		head = head->next;
		y++;
	}
	return (1);
}
