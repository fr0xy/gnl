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
	static char	*tab_line[255];
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int	nb_ligne;
	int	buff_read;
	int	i;
	int flag;

	flag = 0;
	i = 0;
	buff_read = 1;
	if (fd < 0)
		return (-1);
	if (tab_line[fd] != NULL)
		if (tab_line[fd][0] == '\0')
		{
			line[0] = NULL;
			return (0);
		}
	nb_ligne = ft_test_tab_line(tab_line[fd], &i);
	while ((nb_ligne <= 0 && buff_read != 0) || flag == 0)
	{
		if (nb_ligne <= 0)
		{
			while ((buff_read = read(fd, buf, BUFF_SIZE)) > 0 && nb_ligne <= 0)
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
					break;
			}
		}
		if (buff_read == -1)
			return (-1);
		if (nb_ligne == 0 && buff_read == 0)
		{
			line[0] = ft_strdup(tab_line[fd]);
			free(tab_line[fd]);
			tab_line[fd] = NULL;
			flag = 1;
		}
		if (nb_ligne > 0 && flag == 0)
		{
			line[0] = ft_strsub(tab_line[fd], i, nb_ligne);
			tmp = ft_strsub(tab_line[fd], nb_ligne + i, ft_strlen(tab_line[fd]));
			free(tab_line[fd]);
			tab_line[fd] = tmp;
			flag = 1;
		}
		nb_ligne = ft_test_tab_line(tab_line[fd], &i);
	}
	if (buff_read == 0 && nb_ligne == -1)
	{
		tab_line[fd] = ft_strdup("");
		return (0);
	}
	else if (buff_read > 0 || nb_ligne != 0)
			return (1);
	return (-1);
}

int	main(void)
{
	char	*test;
	int	fd;
	int i;

	i = 0;
	fd = 0;
	if ((fd = open("one_big_fat_line.txt", O_RDONLY)) != -1)
	{
		while (i != 2)
		{
			printf("%d\n", get_next_line(fd, &test));
			printf("%s\n", test);
			i++;
		}
		printf("%d\n", i);
	}
	else
		printf("%s\n", "erreur ouverture");
	return (0);
}
