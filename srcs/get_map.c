/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:33:14 by atourret          #+#    #+#             */
/*   Updated: 2021/02/08 14:36:38 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void    aff_map(t_data *data)
{
    int    x;
    int    y;

	y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == ' ')
                printf("\033[31m░\033[0m");
            else if (data->map[y][x] == '|') 
                printf("\033[34m█\033[0m");
            else if (data->map[y][x] == '.')
                printf("\033[%d;%d;%dm┼\033[0m", 128, 25, 22);
            else if (data->map[y][x] == '$')
                printf("\033[33m☺\033[0m");
            else if (ft_ischar("NSEW", data->map[y][x]))
                printf("\033[33m℗\033[0m");
            x++;
        }
        printf("\n");
        y++;
    }
}

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
	aff_map(data);
}

void    flood_fill(t_data *data, int y, int x)
{
    if (y < 0 || x < 0 || y > (data->nb_line - 1) || \
        x > (ft_strlen(data->map[y]) - 1))
        err(data, "La map n'est pas valide.", 0);
    if (ft_ischar("|.?" ,data->map[y][x]))
        return ;
    if (data->map[y][x] == '1')
    {
        data->map[y][x] = '|';
        return ;
    }
    if (data->map[y][x] == '0')
        data->map[y][x] = '.';
    if (data->map[y][x] == '2')
        data->map[y][x] = '$';
    flood_fill(data, y - 1, x);
    flood_fill(data, y + 1, x);
    flood_fill(data, y, x - 1);
    flood_fill(data, y, x + 1);
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
	data->map[y] = 0;
	return (1);
}
