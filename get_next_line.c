#include "get_next_line.h"

char	*cutter(char *buffer)
{
	int		i;
	int		d;
	char	*str;

	i = 0;
	d = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(buffer) - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (buffer[i])
		str[d++] = buffer[i++];
	str[d] = '\0';
	free(buffer);
	return (str);
}

char	*liner(char *buf)
{
	char	*line;
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		check = 1;
	line = (char *)malloc(sizeof(char) * (i + check + 1));
	line[i + check] = '\0';
	while (i >= 0)
	{
		line[i] = buf[i];
		i--;
	}
	return (line);
}

char	*reader(int fd, char *buf, int *flag)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	while (!ft_strchr(buf, '\n') && *flag > 0)
	{
		*flag = read(fd, line, BUFFER_SIZE);
		if (*flag == -1)
		{
			free(line);
			return (NULL);
		}
		line[*flag] = '\0';
		buf = ft_strjoin(buf, line);
	}
	free(line);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;
	int			flag;

	flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = reader(fd, buffer, &flag);
	if (!buffer)
		return (NULL);
	result = liner(buffer);
	buffer = cutter(buffer);
	return (result);
}

