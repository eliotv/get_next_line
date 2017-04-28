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
<<<<<<< HEAD
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
=======

void strjoin_free(char *buff, char **str_read)
{
	char *tmp;
	tmp = ft_strjoin(&buff, *str_read);
	ft_bzero(&buff, BUFF_SIZE + 1);
	free(*str_read);
	*str_read = tmp;
}


void str_read(char *buff, char **str_read)
{
	if (*str_read == 0)
	{
		*str_read = strdup(&buff);
		ft_bzero(&buff, BUFF_SIZE + 1);
		return ;
	}
	strjoin_free(buff, str_read);
>>>>>>> 6c5d56766999d6f9ac73d7ab592db7e27199e815
}

int end_line(char **str_read, char **line)
{
<<<<<<< HEAD
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
=======
	size_t str_len;
	str_len = ft_strlen(*str_read);
	*line = strdup(*str_read);
	ft_bzero(*str_read, str_len);
	return (1);
}

int set_line(char **str_read, char **file_line, size_t len)
{
	*file_line = strdup(*str_read);
	*str_read = ft_memmove(*str_read, *str_read + len + 1, ft_strlen(*str_read));
	return (1);
}

int get_next_line(const int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	char tmp;
	int bytes_read;
	static char str_from_file;

	if (fd < 0 || !*line || BUFF_SIZE <= 0)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((bytes_read = read(0, buff, BUFF_SIZE)) != 0)
	{
		str_read(buff, &str_from_file);
		if ((tmp = ft_strchr(str_from_file, '\n')) != 0)
			return (set_line(str_from_file, line, tmp - str_from_file));
	}
	if(!str_from_file)
		return (0);
	else if ((tmp = ft_strchr(str_from_file, '\n')) != 0)
		return (set_line(str_from_file, line, tmp - str_from_file));
	else if (ft_strlen(str_from_file) > 0)
		return (end_line(str_from_file, line));
	ft_strdel(&str_from_file);
>>>>>>> 6c5d56766999d6f9ac73d7ab592db7e27199e815
	return (0);
}
