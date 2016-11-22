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

int	get_next_line(const int fd, char **line)
{
	static char	*tab_line[214748364];
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int	nb_ligne;
	int	buff_read;
	int	i;

	i = 0;
	nb_ligne = ft_test_tab_line(tab_line[fd], &i);
	if (nb_ligne > 0)
	{
		line[0] = ft_strsub(tab_line[fd], i, nb_ligne);
		tmp = ft_strsub(tab_line[fd], nb_ligne + i, ft_strlen(tab_line[fd]));
		free(tab_line[fd]);
		tab_line[fd] = tmp;
		return (1);
	}
	else
	{
		while ((buff_read = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[buff_read] = '\0';
			if ((nb_ligne = ft_test_tab_line(tab_line[fd], &i)) == -1)
				tab_line[fd] = ft_strdup(buf);
			else if (nb_ligne == 0)
			{
				tmp = ft_strjoin(tab_line[fd], buf);
				free(tab_line[fd]);
				tab_line[fd] = ft_strdup(tmp);
			}
			if ((nb_ligne = ft_test_tab_line(tab_line[fd], &i)) > 0)
			{
				line[0] = ft_strsub(tab_line[fd], i, nb_ligne);
				tmp = ft_strsub(tab_line[fd], nb_ligne + i, ft_strlen(tab_line[fd]));
				free(tab_line[fd]);
				tab_line[fd] = tmp;
				return (1);
			}
		}
	}
	return (-1);
}

int	main(void)
{
	char	*test;
	int	fd;

	fd = 0;
	if ((fd = open("get_next_line.h", O_RDONLY)) != -1)
	{
		if (get_next_line(fd, &test) == 1)
		{	
			printf("%s\n", test);
			if (get_next_line(fd, &test) == 1)
			{	
				printf("%s\n", test);
				if (get_next_line(fd, &test) == 1)
				{	
					printf("%s\n", test);
				}
				else
					printf("%s\n", "erreur lecture ligne 3");
			}
			else
				printf("%s\n", "erreur lecture ligne 2");
		}
		else
			printf("%s\n", "erreur lecture ligne 1");
	}
	else
		printf("%s\n", "erreur ouverture");
	return (0);
}
