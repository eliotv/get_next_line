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

int read_file_bytes(int const fd, char **file)
{
	static char buff[BUFF_SIZE + 1];
	int	byte_count;
	char *nstr;

	byte_count = read(fd, buff, BUFF_SIZE);
	if (byte_count > 0)
	{
		nstr = ft_strjoin(*file, buff);
		if (!nstr)
			return (-1);
		free (*file);
		*file = nstr;
	}
	return (byte_count);
}

int get_next_line(int const fd, char **line)
{
	static char *file;
	char *newline_index;
	int  ret;

	if (!file && (file = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	newline_index = ft_strchr(file, NL);
	while (newline_index == NULL)
	{
		ret = read_file_bytes(fd, &file);
		if (ret == 0)
		{
			if ((newline_index = ft_strchr(file, '\0')) == file)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			newline_index = ft_strchr(file, NL);
	}
	*line = ft_strsub(file, 0, NL);
	if (!*line)
		return (-1);
	newline_index = ft_strdup(newline_index + 1);
	free(file);
	file = newline_index;
	return (1);
}
