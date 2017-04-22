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

int read_file_bytes(int const fd, char **file)
{
	char buff[BUFF_SIZE + 1];
	int	byte_count;
	char *nstr;

	ft_bzero(buff, BUFF_SIZE + 1);
	printf("1");
	byte_count = read(fd, buff, BUFF_SIZE);
	printf("2");
	buff[byte_count] = '\0';
	printf("3");
	if (byte_count > 0)
	{
		nstr = ft_strjoin(*file, buff);
		if (!nstr)
			return (-1);
		free (*file);
		printf("4");
		*file = nstr;
		printf("5");
	}
	printf("6");
	return (byte_count);
}

int get_next_line(int const fd, char **line)
{
	static char *str;
	char *newline_index;
	int  ret;

	if (fd < 0 || read(0, str, 0) < 0 || !line)
		return (-1);
	if (!str)
		str = (char *)ft_memalloc(sizeof(char));
	//while (!(newline_index = ft_strchr(str, '\n')))
	while (ret == read_file_bytes(fd, &str) > 0)
	{

		newline_index = ft_strchr(str, '\n');
		/*ret = read_file_bytes(fd, &str);
		if (ret == 0 && !newline_index)*/
		if (str[0] == 0) 
			return (0);
		*line = str;
		str = NULL;
		return (1);	
	}
	if (ret < 0)
		return (-1);
	*line = ft_strsub(str, 0, newline_index - str);
	if (!*line)
		return (-1);
	newline_index = ft_strdup(newline_index + 1);
	free(str);
	str = newline_index;
	return (1);
}
