/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 05:32:50 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/28 22:40:04 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_ttl(char *str, int *i)
{
	int	j;

	*i = 0;
	j = 0;
	if (str != NULL)
	{
		if (str[*i] == '\n')
			*i = *i + 1;
		while (str[*i + j] != '\0' && str[*i + j] != '\n')
			j++;
		if (str[*i + j] == '\n')
			return (j + 1);
		else if (j != 0)
			return (0);
	}
	return (-1);
}

int		lecture(const int fd, char **tmp, int i)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		nb_line;
	char	*tamp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		nb_line = ft_ttl(tmp[0], &i);
		if (nb_line >= 0)
		{
			tamp = ft_strdup(tmp[0]);
			free(tmp[0]);
			tmp[0] = ft_strjoin(tamp, buff);
			free(tamp);
		}
		else
			tmp[0] = ft_strdup(buff);
		if (nb_line > 0)
			return (-2);
	}
	return (ret);
}

char	*set_line(char **str)
{
	char	*tmp;
	char	*line;
	int		nb_line;
	int		i;

	nb_line = ft_ttl(str[0], &i);
	line = ft_strsub(str[0], i, nb_line - 1);
	tmp = ft_strsub(str[0], nb_line + i - 1, ft_strlen(str[0]));
	free(str[0]);
	str[0] = ft_strdup(tmp);
	free(tmp);
	return (line);
}

void	set_end(int *etat, char **str, char **line, int nb_line)
{
	if (str[0] != NULL)
	{
		*etat = 1;
		if (str[0][0] == '\n' && ft_strlen(str[0]) == 1)
			line[0] = ft_strdup("");
		else
			line[0] = ft_strsub(str[0], nb_line, ft_strlen(str[0]));
		free(str[0]);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_tab	tab[5000];
	t_int			var;

	var.ret = 1;
	if ((fd == 0 || fd > 2) && tab[fd].etat == 0)
	{
		while (var.ret > 0)
			var.ret = lecture(fd, &tab[fd].str, var.i);
		if (var.ret <= 0 && tab[fd].etat == 0 && (var.nb_line =
					ft_ttl(tab[fd].str, &var.i)) == -1 && tab[fd].str == NULL)
			return (var.ret);
		if ((var.nb_line = ft_ttl(tab[fd].str, &var.i)) <= 0 && var.ret == 0)
			set_end(&tab[fd].etat, &tab[fd].str, &line[0], var.nb_line + var.i);
		else if (tab[fd].etat == 0)
			line[0] = set_line(&tab[fd].str);
		if (var.ret == 0 && (var.nb_line = ft_ttl(tab[fd].str, &var.i)) == -1)
			tab[fd].etat = 1;
		return (1);
	}
	else if ((fd == 0 || fd > 2) && tab[fd].etat == 1)
	{
		line[0] = NULL;
		return (0);
	}
	return (-1);
}
