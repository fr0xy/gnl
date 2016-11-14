#include "get_next_line.h"

int	ft_test_tab_line(char **tab_line)
{
	int	i;

	i = 0;
	if (tab_line != NULL)
	{
		while (tab_line[i] != 0)
			i++;
	}
	return (i);
}

int	get_next_line(const int fd, char **line)
{
	static char	**tab_line;
	char	buf[BUFF_SIZE];
	int	i;
	char	*str;
	int	nb_ligne;
	int	buff_read;

	nb_ligne = ft_test_tab_line(tab_line);
	if (nb_ligne > 1)
	{
		line[0] = ft_strdup(tab_line[0]);
		free(tab_line[0]);
		tab_line = &tab_line[1];
		return (1);
	}
	else
	{
		while ((buff_read = read(fd, buf, BUFF_SIZE)) > 0)
		{
			i = 0;
			if ((nb_ligne = ft_test_tab_line(tab_line)) == 0)
				tab_line = ft_strsplit(buf, '\n');
			else if (nb_ligne == 1)
			{
				str = ft_strjoin(tab_line[0], buf);
				free(tab_line[0]);
				tab_line = ft_strsplit(str, '\n');
			}
			while (buf[i] != '\n' && i <= buff_read)
				i++;
			if (buf[i] == '\n')
			{
				line[0] = ft_strdup(tab_line[0]);
				free(tab_line[0]);
				tab_line = &tab_line[1];
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
//	if ((fd = open("get_next_line.h", O_RDONLY)) != -1)
//	{
		if (get_next_line(5, &test) == 1)
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
//	}
//	else
//		printf("%s\n", "erreur ouverture");
	return (0);
}
