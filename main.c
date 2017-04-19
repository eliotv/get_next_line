/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:32:32 by evanheum          #+#    #+#             */
/*   Updated: 2017/04/17 17:53:32 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		return (2);
	while(get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (ac == 2)
		close(fd);
}
