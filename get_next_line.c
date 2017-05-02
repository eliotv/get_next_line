/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:37:02 by evanheum          #+#    #+#             */
/*   Updated: 2017/05/02 14:37:11 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				nl_search(const int fd, char **str, char **line)
{
	char *newline;

	while ((newline = ft_strchr(str[fd], '\n')))
	{
		*line = ft_strndup(str[fd], (newline - str[fd]));
		str[fd] = newline + 1;
		return (1);
	}
	if (*(str[fd]))
	{
		*line = ft_strdup(str[fd]);
		ft_bzero(str[fd], ft_strlen(str[fd]));
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str[FD_MAX];
	char		*tmp;
	int			byte_c;

	while ((byte_c = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[byte_c] = '\0';
		if (byte_c == -1)
			return (-1);
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
	}
	return (nl_search(fd, str, line));
}
