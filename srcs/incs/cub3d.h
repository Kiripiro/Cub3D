/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:28:44 by atourret          #+#    #+#             */
/*   Updated: 2021/02/05 18:00:28 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include "minilibx_mms_20200219/mlx.h"

typedef	struct		s_data
{
	int		fd;

	int		length;
	int		width;
	int		f_r;
	char	*no;
	int		f_no;
	char	*so;
	int		f_so;
	char	*we;
	int		f_we;
	char	*ea;
	int		f_ea;

	char	*s;
	int		f_s;
	int		f_f;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		f_c;
	int		sky_r;
	int		sky_g;
	int		sky_b;

	char	*line;
	char	**map;
	
	int		i;
	size_t	len;
	int		sprite;
	int		nb_line;

	int		y;
	int		x;
}					t_data;

void		err(t_data *data, char *error, char c);
void		parsing(t_data *data, char *path);
void		pre_treatment(t_data *data, char c);
void		skip_whitespaces(t_data *data, int oui);
int			get_colors_f(t_data *data);
int			get_colors_c(t_data *data);
int			make_map(t_data *data, t_list *head);
void		flood_fill(t_data *data, int y, int x);
void		clean_map(t_data *data);
void		free_data(t_data *data);

#endif
