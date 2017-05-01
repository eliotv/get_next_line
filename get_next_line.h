/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:16:12 by evanheum          #+#    #+#             */
/*   Updated: 2017/04/17 18:18:42 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 16 
#define FD_MAX 4864

typedef struct		gnl_val
{
	char *str[FD_MAX];
	char *tmp;
	int  byte_c;
}					t_gnl;
int get_next_line(const int fd, char **line);

#endif
