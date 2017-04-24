/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:40:52 by evanheum          #+#    #+#             */
/*   Updated: 2017/04/18 21:10:09 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

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
}

int end_line(char **str_read, char **line)
{
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
	return (0);
}
