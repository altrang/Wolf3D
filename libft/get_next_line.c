/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:16:04 by atrang            #+#    #+#             */
/*   Updated: 2016/03/28 16:44:08 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char		*ft_fill_line(char *str, char *line)
{
	char	*tmp;
	int		cmpt;
	int		cmpt2;

	cmpt = 0;
	cmpt2 = -1;
	while (str[cmpt] != '\0' && str[cmpt] != '\n')
		cmpt++;
	tmp = line;
	line = (char *)ft_memalloc(sizeof(char) * (ft_strlen(line) + cmpt) + 1);
	cmpt = -1;
	while (tmp[++cmpt] != '\0')
		line[cmpt] = tmp[cmpt];
	while (str[++cmpt2] != '\0' && str[cmpt2] != '\n')
	{
		line[cmpt] = str[cmpt2];
		cmpt++;
	}
	return (line);
}

static void	init_buf(t_gnl **gnl, char **line)
{
	*line = (char *)ft_memalloc(1);
	if (!*gnl)
	{
		*gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		(*gnl)->buf = (char *)ft_memalloc(BUFF_SIZE + 1);
		(*gnl)->ptr = NULL;
	}
}

int			get_next_line(int const fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	init_buf(&gnl, line);
	while (gnl->ptr || (ret = read(fd, gnl->buf, BUFF_SIZE)))
	{
		if (gnl->ptr)
		{
			*line = ft_fill_line(gnl->ptr + 1, *line);
			if ((gnl->ptr = ft_strchr(gnl->ptr + 1, '\n')))
				return (1);
			ret = read(fd, gnl->buf, BUFF_SIZE);
		}
		if (ret == -1)
			return (ret);
		gnl->buf[ret] = '\0';
		*line = ft_fill_line(gnl->buf, *line);
		if ((gnl->ptr = ft_strchr(gnl->buf, '\n')))
			return (1);
	}
	return (**line || ret ? 1 : 0);
}
