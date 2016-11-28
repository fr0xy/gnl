/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 05:48:14 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/28 22:40:33 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 4
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_tab
{
	char	*str;
	int		etat;
}				t_tab;
typedef struct	s_int
{
	int		ret;
	int		nb_line;
	int		i;
}				t_int;
int				get_next_line(const int fd, char **line);
#endif
