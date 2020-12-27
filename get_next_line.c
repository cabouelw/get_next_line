/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:54:56 by cabouelw          #+#    #+#             */
/*   Updated: 2020/01/02 15:55:02 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_and_cut(char **buf, char **line, char *new_line)
{
	char *tmp;

	*line = ft_substr(*buf, 0, new_line - *buf);
	tmp = *buf;
	*buf = ft_substr(*buf, new_line - *buf + 1, BUFFER_SIZE);
	free(tmp);
	return (1);
}

static int	ft_final_line(char **tmp, char **buf, char **line)
{
	*line = ft_substr(*buf, 0, ft_strlen(*buf));
	free(*tmp);
	free(*buf);
	*buf = 0;
	return (0);
}

static int	ft_isfalse(char **buf, char **tmp)
{
	free(*tmp);
	free(*buf);
	*buf = 0;
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static char		*buf;
	char			*tmp;
	char			*p;
	char			*new_line;
	int				i;

	if (BUFFER_SIZE < 0 || !line)
		return (-1);
	if ((new_line = ft_strchr(buf, '\n')))
		return (ft_find_and_cut(&buf, line, new_line));
	if (!(tmp = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if ((i = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[i] = 0;
		p = buf;
		buf = ft_strjoin(buf, tmp);
		free(p);
		free(tmp);
		return (get_next_line(fd, line));
	}
	if (i == 0)
		return (ft_final_line(&tmp, &buf, line));
	return (ft_isfalse(&buf, &tmp));
}
