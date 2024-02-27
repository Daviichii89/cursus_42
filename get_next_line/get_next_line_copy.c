#include "get_next_line.h"

char *extract_line(char *buffer)
{
	char *line;
	int i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0 || buffer[1] == 0)
		return (NULL);
	line = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (!line)
		return (free(buffer), NULL);
	buffer[i + 1] = '\0';
	return (line);
}

char *read_file(char *buffer, int fd)
{
	char *temp;
	int bytes_read;

	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp), NULL);
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(temp);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(buffer, '\n'))
		buffer = read_file(buffer, fd);
	if (!buffer)
		return (free(buffer), NULL);
	line = extract_line(buffer);
	return (line);
}

// https://medium.com/@lannur-s/chapter-5-expanding-the-basin-malloc-char-basin-buffer-8c1eed59cbd1
