#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			bytes_read;

	line = NULL;
	temp = ft_strchr(buffer, '\n');
	while (!temp)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0 && !line)
			return (NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strchr(buffer, '\n');
	}
	*temp = '\0';
	line = ft_strdup(buffer);
	ft_strcpy(buffer, temp + 1);
	return (line);
}
