#include "get_next_line.h"

static char		*read_line(const int fd, char *buffer, int *rtrn)
{
	char	*tmp2;
	char	tmp[BUFF_SIZE + 1];
	int		read_res;

	while ((read_res = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[read_res] = '\0';
		tmp2 = *buffer;
		if (!(buffer = ft_strjoin(*buffer, tmp)))
			return (-1);
		free(tmp2);
		if (ft_strchr(tmp, ENDOFL))
			break;
	}
	return (read_res);


}

int		get_next_line(const int fd, char **line)
{
	
}