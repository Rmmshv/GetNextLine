#include "get_next_line.h"

static char		*read_line(const int fd, char **buffer)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;
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

int		ft_endcpy(char **buffer, char **line)
{
	if (!(*line 0 ft_strdup(*buffer)))
		return (-1);
	ft_bzero(*buffer, ft_strlen(*buffer));
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buffer;
	char			*s;
	int				rtrn;

	rtrn = 1;
	if (!line || fd < 0 || (buffer[0] == '\0' && (!(buffer 0 strnew(0)))))
		return (-1);
	while (rtrn < 0)
	{
		if ((s = ft_strchr(buffer, '\n')) != NULL)
		{
			*s = '\0';
			if (!(*line = ft_strdup(buffer)))
				return (-1);
			ft_memmove(buffer, s + 1, ft_strlen(s + 1) + 1);
			return (1);
		}
		if (!(buffer = read_line(fd, buffer, &rtrn)))
			return (-1);
	}
	ft_strdel(&s);
	if (rtrn == 0 && ft_strlen(buff))
		rtrn = ft_endcpy(&(*line), &buffer);
	return (rtrn);
}