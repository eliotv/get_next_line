/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:55:30 by evanheum          #+#    #+#             */
/*   Updated: 2017/04/24 18:44:14 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void fill_line(char **file_str, char *buff)
{
	char *tmp;

	if (*file_str == 0)
	{
		*file_str = ft_strdup(buff);
		ft_bzero(buff, BUFF_SIZE + 1);
		return ;
	}
	tmp = ft_strjoin(*file_str, buff);
	free(*file_str);
	ft_bzero(buff, BUFF_SIZE + 1);
	*file_str = tmp;
}

int merge_line(char **file_str, char **line, size_t len)
{
	*line = ft_strndup(*file_str, len);
	*file_str = ft_memmove(*file_str, *file_str + len + 1, ft_strlen(*file_str));
		return (1);
}

int end_line(char **file_str, char **line)
{
	size_t len;

	len = ft_strlen(*file_str);
	*line = ft_strdup(*file_str);
	ft_bzero(*file_str, len);
	return (1);
}

int get_next_line(int const fd, char **line)
{
	static char *file_str[4864];
	char buff[BUFF_SIZE + 1];
	char *tmp;
	int bytes_read;

	if  (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((bytes_read = read(fd, buff, BUFF_SIZE)))
	{
		fill_line(&file_str[fd], buff);
		if ((tmp = ft_strchr(file_str[fd], '\n')) != 0)
			return (merge_line(&file_str[fd], line, tmp - file_str[fd]));
	}
	if (!file_str[fd])
		return (0);
	else if ((tmp = ft_strchr(file_str[fd], '\n')) != 0)
		return (merge_line(&file_str[fd], line, tmp - file_str[fd]));
	else if (ft_strlen(file_str[fd]) > 0)
		return (end_line(&file_str[fd], line));
	free(&file_str[fd]);
	return (0);
}
