/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 05:32:50 by rchoffar          #+#    #+#             */
/*   Updated: 2016/12/02 17:40:38 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_tab	*find_node(int fd, t_tab **lst)
{
	t_tab	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		if ((tmp = (t_tab*)malloc(sizeof(t_tab))) == NULL)
			return (NULL);
		tmp->fd = fd;
		tmp->str = NULL;
		tmp->next = *lst;
		*lst = tmp;
	}
	return (tmp);
}

char	*couper_decaler(char *str, char **line)
{
	char	*tmp;
	int		size;

	size = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n'));
	line[0] = ft_strsub(str, 0, size);
	tmp = ft_strsub(str, size + 1, ft_strlen(str));
	free(str);
	if (ft_strlen(tmp) != 0)
		str = ft_strdup(tmp);
	else
		str = NULL;
	free(tmp);
	return (str);
}

char	*buff_cat(char *buff, char *str, char **line)
{
	char	*tmp;

	if (str == NULL)
		str = ft_strdup(buff);
	else
	{
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin(tmp, buff);
		free(tmp);
	}
	if (ft_strchr(str, '\n') != NULL)
		str = couper_decaler(str, &line[0]);
	else
		line[0] = NULL;
	return (str);
}

char	*buff_end(char *str, char **line)
{
	if (str != NULL)
	{
		if (ft_strchr(str, '\n') != NULL)
			str = couper_decaler(str, &line[0]);
		else if (str != NULL)
		{
			line[0] = ft_strdup(str);
			free(str);
			str = NULL;
		}
		else
			line[0] = NULL;
	}
	else
		line[0] = NULL;
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static t_tab	*lst;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_tab			*tmp;

	if (fd < 0 || fd == 1 || fd == 2)
		return (-1);
	tmp = find_node(fd, &lst);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp->str = buff_cat(buff, tmp->str, &line[0]);
		if (line[0] != NULL)
			return (1);
	}
	if (ret == -1)
		return (ret);
	tmp->str = buff_end(tmp->str, &line[0]);
	if (line[0] != NULL)
		return (1);
	return (0);
}
