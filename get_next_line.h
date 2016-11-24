#ifndef GET_NEXT_LINE

# define GET_NEXT_LINE
# define BUFF_SIZE 4
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

int	get_next_line(const int fd, char **line);
#endif
