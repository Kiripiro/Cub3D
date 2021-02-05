/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:28:19 by atourret          #+#    #+#             */
/*   Updated: 2021/02/05 15:32:17 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	skip_whitespaces(t_data *data, int oui)
{
	if (oui == 0)
		while (!ft_isalpha(data->line[data->i]))
			data->i++;
	else if (oui == 1)
		while (data->line[data->i] == 9 || data->line[data->i] == 32)
			data->i++;
}

int		get_res_textures(t_data *data)
{
	char	*tmp;
	char	c;

	skip_whitespaces(data, 0);
	if (ft_isalpha(data->line[data->i]))
		c = data->line[data->i];
	if (data->line[data->i + 1] == 'O')
		data->sprite = 0;
	if (data->line[data->i + 1] == 'A' || data->line[data->i + 1] == 'E' || \
			data->line[data->i + 1] == 'O')
		data->i++;
	data->i++;
	skip_whitespaces(data, 1);
	pre_treatment(data, c);
	c = 0;
	return (0);
}

int		verif_pre_treatment(t_data *data)
{
	if (data->f_r > 1 || data->f_no > 1 || data->f_so > 1 || data->f_we > 1 || \
			data->f_ea > 1 || data->f_s > 1 || data->f_f > 1 || data->f_c > 1)
		err(data, "Merci de supprimer les doublons dans les parametres.",  0);
	if (data->f_r && data->f_no && data->f_so && data->f_ea && data->f_ea && \
			data->f_s && data->f_f && data->f_c)
		return (0);
	return (1);
}

int		parsing(t_data *data, char *path)
{
	int		verif;
	t_list	*lst;
	t_list	*head;

	lst = NULL;
	head =  NULL;
	data->fd = open(path, O_RDONLY);
	while ((verif = get_next_line(data->fd, &data->line)))
	{
		if (verif < 0)
			err(data, "Fichier introuvable.", 0);
		data->sprite = 1;
		data->i = 0;
		if (ft_strncmp(data->line, "", 1))
		{
			if (verif_pre_treatment(data))
				get_res_textures(data);
			else if (!verif_pre_treatment(data))
			{
				lst = ft_lstnew(data->line);
				ft_lstadd_back(&head, lst);
				data->nb_line++;
			}
		}
	}
	make_map(data, head);
	dprintf(1, "\n|%d %d|\n", data->length, data->width);
	dprintf(1, "|%s|\n", data->no);
	dprintf(1, "|%s|\n", data->so);
	dprintf(1, "|%s|\n", data->we);
	dprintf(1, "|%s|\n", data->ea);
	dprintf(1, "|%s|\n", data->s);
	dprintf(1, "|%d,%d,%d|\n", data->floor_r, data->floor_g, data->floor_b);
	dprintf(1, "|%d,%d,%d|\n", data->sky_r, data->sky_g, data->sky_b);
	dprintf(1, "\n|%s|\n", data->map[0]);
	dprintf(1, "|%s|\n", data->map[1]);
	dprintf(1, "|%s|\n", data->map[2]);
	dprintf(1, "|%s|\n", data->map[3]);
	dprintf(1, "|%s|\n", data->map[4]);
	dprintf(1, "|%s|\n", data->map[5]);
	dprintf(1, "|%s|\n", data->map[6]);
	dprintf(1, "|%s|\n", data->map[7]);
	dprintf(1, "|%s|\n", data->map[8]);
	dprintf(1, "|%s|\n", data->map[9]);
	dprintf(1, "|%s|\n", data->map[10]);
	dprintf(1, "|%s|\n", data->map[11]);
	dprintf(1, "|%s|\n", data->map[12]);
	dprintf(1, "|%s|\n", data->map[13]);
	return (0);
}
