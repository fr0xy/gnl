#include "get_next_line.h"

int	ft_test_tab_line(char *str, int *i)
{
	int	j;

	*i = 0;
	j = 0;
	if (str != NULL)
	{
		while (str[*i] == '\n')
			*i = *i + 1;
		while (str[*i + j] != '\0' && str[*i + j] != '\n')
			j++;
		if (str[*i + j] == '\n' && j != 0)
			return (j);
		else if (j != 0)
			return (0);
	}
	return (-1);
}

int	lecture(const int fd, char **tmp, int i)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		nb_line;
	char	*tamp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		nb_line = ft_test_tab_line(tmp[0], &i);
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

	nb_line = ft_test_tab_line(str[0], &i);
	line = ft_strsub(str[0], i, nb_line);
	tmp = ft_strsub(str[0], nb_line + i, ft_strlen(str[0]));
	free(str[0]);
	str[0] = ft_strdup(tmp);
	free(tmp);
	return (line);
}

int	get_next_line(const int fd, char **line)
{
	static t_tab	tab[255];
	int				retour;
	int				nb_line;
	int				i;

	i = 0;
	if (fd >= 0 && tab[fd].etat == 0)
	{
		while ((retour = lecture(fd, &tab[fd].str, i)) > 0);
		if ((nb_line = ft_test_tab_line(tab[fd].str, &i)) == 0 && retour == 0)
		{
			tab[fd].etat = 1;
			line[0] = ft_strsub(tab[fd].str, nb_line + i, ft_strlen(tab[fd].str));
			free(tab[fd].str);
		}
		else if (retour == -1 && tab[fd].etat == 0 && nb_line == -1)
			return (-1);
		else
			line[0] = set_line(&tab[fd].str);
		if (retour == 0 && (nb_line = ft_test_tab_line(tab[fd].str, &i)) == -1)
			tab[fd].etat = 1;
		return (1);
	}
	else if (fd >= 0 && tab[fd].etat == 1)
	{
		line[0] = NULL;
		return (0);
	}
	return (-1);
}

int	main(void)
{
	char	*test;
	int	fd;
	int i;

	i = 0;
	fd = 0;
	if ((fd = open("test", O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &test) > 0)
		{
			printf("test : %s\n", test);
			i++;
		}
			printf("%d\n", i);
	}
	else
		printf("%s\n", "erreur ouverture");
	return (0);
}
