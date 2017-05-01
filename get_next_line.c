#include "get_next_line.h"

int		read_file(const int fd, char **line)
{
	int byte_c;
	char *tmp;
	char buff[BUFF_SIZE + 1];

	ft_bzero(buff, BUFF_SIZE + 1);
	byte_c = read(fd, buff, BUFF_SIZE);
	if (byte_c > 0)
	{
		buff[byte_c] = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (byte_c);
}

int get_next_line(const int fd, char **line)
{
	static t_gnl			buf;


	if (fd < 0 || !line || fd > FD_MAX)
		return (-1);
	if (!buf.str[fd])
		buf.str[fd] = ft_memalloc(sizeof(char) * BUFF_SIZE);
	while ((buf.tmp = ft_memchr(buf.str[fd], '\n', ft_strlen(buf.str[fd]))) == NULL)
	{
		buf.byte_c = read_file(fd, &buf.str[fd]);
		//printf("%d\n", buf.byte_c);
		if (buf.byte_c < 0)
			return (-1);
		if (buf.byte_c == 0)
		{
			if (buf.str[fd][0] == '\0')
				return (0);
			*line = buf.str[fd];
			buf.str[fd] = NULL;
			return (1);
		}
	}
	//*line = ft_strjoin (buf.str[fd], buf.tmp);
	*line = ft_strsub(buf.str[fd], 0, buf.tmp - buf.str[fd]);
	ft_strcpy(buf.str[fd], buf.tmp + 1);
	return (1);
}
