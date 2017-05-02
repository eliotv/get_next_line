#include "get_next_line.h"


int		get_next_line(const int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
    static char *str[FD_MAX];
    char *tmp;
    char *newline;
    int  byte_c;	

	// free str[fd] after searching for new lines.
	// make sure to have a pointer to the first byte in str[fd] so you can free the WHOLE thing.
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
