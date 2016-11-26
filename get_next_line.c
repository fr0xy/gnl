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

int	lecture(const int fd, char **tmp)
{
	int	ret;
	char	buff[BUFF_SIZE + 1];
	int	nb_line;
	int	i;
	char	*tamp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		nb_line = ft_test_tab_line(tmp[0], i);
		if (nb_line >= 0)
		{
			tamp = ft_strdup(tmp[0]);
			free(tmp[0];
			tmp[0] = ft_strjoin(tamp, buff);
			free(tamp);
			return (nb_line)
		}
		else
			tmp[0] = ft_strdup(buff);
		return (0)
	}
	return (-1)
}

int	get_next_line(const int fd, char **line)
{
	static char	*tab[255];
	int		retour;
	int		nb_line;
	
	while ((retour = lecture(fd, &tab[fb])) == 0)
	{
	}
		
		
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
