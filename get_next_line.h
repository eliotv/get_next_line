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

#define BUFF_SIZE 1
#define NL '\n'
int get_next_line(int const fd, char **line);

#endif
