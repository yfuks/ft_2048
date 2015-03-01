/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 15:51:20 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 16:37:19 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*return_char_buff(int const fd)
{
	char	*buff;
	char	*tmp[2];

	buff = ft_strnew(BUFF_SIZE);
	tmp[0] = NULL;
	ft_memset(buff, '\0', BUFF_SIZE + 1);
	while (read(fd, buff, BUFF_SIZE))
	{
		tmp[1] = tmp[0];
		tmp[0] = ft_strappend(tmp[1], buff);
		if (tmp[1])
			free(tmp[1]);
		if (ft_strchr(tmp[0], '\n'))
		{
			free(buff);
			return (tmp[0]);
		}
		ft_memset(buff, '\0', BUFF_SIZE + 1);
	}
	free(buff);
	return (tmp[0]);
}

static t_file	*new_file(int fd)
{
	t_file	*file;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	file->fd = fd;
	file->buff = return_char_buff(fd);
	file->next = NULL;
	return (file);
}

static t_file	*return_file_info(int fd, t_file *file)
{
	t_file	*cursor;
	t_file	*previous_cursor;

	cursor = file;
	if (file == NULL)
		cursor = new_file(fd);
	else
	{
		while (cursor != NULL)
		{
			previous_cursor = cursor;
			if (cursor->fd == fd)
				return (cursor);
			cursor = cursor->next;
		}
		previous_cursor->next = new_file(fd);
		cursor = previous_cursor->next;
	}
	return (cursor);
}

static int		return_get_next_line(t_file *file, char **line, int i)
{
	if (!file->buff || (!ft_strchr(file->buff, '\n') && i == 0))
		return (0);
	if (!ft_strchr(file->buff, '\n'))
	{
		*line = file->buff;
		file->buff = NULL;
		return (1);
	}
	if (file->buff[0] == '\n')
	{
		*line = ft_strnew(1);
		file->buff = ft_strsub(file->buff, 1, ft_strlen(file->buff));
	}
	else
	{
		*line = ft_strsub(file->buff, 0, i);
		file->buff = ft_strsub(file->buff, i + 1, ft_strlen(file->buff) - i);
	}
	if (!file->buff)
		file->buff = ft_strnew(1);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*f[2];
	int				i;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (!f[1])
	{
		f[1] = return_file_info(fd, f[1]);
		f[0] = f[1];
	}
	else
		f[0] = return_file_info(fd, f[1]);
	i = 0;
	while (f[0]->buff && f[0]->buff[i] != '\n')
	{
		while (f[0]->buff[i] != '\n' && f[0]->buff[i])
			i++;
		if (f[0]->buff[i] == 0)
		{
			f[0]->buff = ft_strappend(f[0]->buff, return_char_buff(f[0]->fd));
			if (!f[0]->buff[i])
				return (return_get_next_line(f[0], line, i));
		}
	}
	return (return_get_next_line(f[0], line, i));
}
