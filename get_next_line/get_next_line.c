#include "get_next_line.h"

char	*free_store(char *buffer)
{
	char		*store;
	ssize_t		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0 || buffer[1] == 0)
		return (NULL);
	store = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (*store == 0)
	{
		free(store);
		store = NULL;
	}
	buffer[i + 1] = 0;
	return (store);
}

char	*read_extract_line(int fd, char *store, char *buffer)
{
	char		*temp;
	ssize_t		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(store);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!store)
			store = ft_strdup("");
		temp = store;
		store = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	char		*buffer;
	
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(store), free(buffer), store = NULL, buffer = NULL, NULL);
	if (!buffer)
		return (NULL);
	line = read_extract_line(fd, store, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	store = free_store(line);
	return (line);
}
