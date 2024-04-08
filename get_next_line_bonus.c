#include "get_next_line_bonus.h"

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
		if (!buf)
		{
			free(buf);
			return (NULL);
		}
	}
	free(line);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*result;
	int			flag;

	flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	buffer[fd] = reader(fd, buffer[fd], &flag);
	if (!buffer[fd])
		return (NULL);
	result = liner(buffer[fd]);
	buffer[fd] = cutter(buffer[fd]);
	return (result);
}

int main()
{
    char *first;
    char *second;

    int fd;
    int fd_b;
    fd = open("./get_next_line.h",   O_RDONLY);
    fd_b = open("/home/d0s3nt/42_projects/get_next_line/get_next_line_bonus.h", O_RDONLY);
    printf("\n first :: \n");
    while(1)
    {
        first = get_next_line(fd);
        if (!first)
            break ;
        printf("%s", first);
        free(first);
    }

    printf("\n second :: \n");
    while(1)
    {
        second = get_next_line(fd_b);
        if (!second)
            break ;
        printf("%s", second);
        free(second);
    }

}