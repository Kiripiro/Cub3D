/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:44:58 by atourret          #+#    #+#             */
/*   Updated: 2021/02/01 14:16:50 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_clean_line(char *new_line, char **line, int r)
{
	size_t	i;
	size_t	length;
	char	*tmp;

	length = ft_strlen(new_line);
	i = 0;
	while (new_line[i] && new_line[i] != '\n')
		i++;
	if (i < length)
	{
		*line = ft_substr(new_line, 0, i);
		tmp = ft_substr(&new_line[i + 1], 0, length - i - 1);
		if (new_line)
			free(new_line);
		new_line = tmp;
	}
	else if (r == 0)
	{
		*line = ft_strdup(new_line);
		free(new_line);
		new_line = 0;
	}
	return (new_line);
}

char	*ft_make_line(char *buff, char *new_line)
{
	char	*tmp;

	if (new_line)
	{
		tmp = ft_strjoin(new_line, buff);
		free(new_line);
		new_line = tmp;
	}
	else
		new_line = ft_strdup(buff);
	return (new_line);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*new_line[4096];
	int				r;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	while ((r = read(fd, &buff, BUFFER_SIZE)))
	{
		if (r <= 0)
			return (r);
		buff[r] = '\0';
		new_line[fd] = ft_make_line(buff, new_line[fd]);
		if (ft_strchr(buff, 10))
			break ;
	}
	if (r <= 0 && !new_line[fd])
	{
		*line = ft_strdup("");
		return (r);
	}
	new_line[fd] = ft_clean_line(new_line[fd], line, r);
	if (r <= 0 && !new_line[fd])
		return (r);
	return (1);
}
