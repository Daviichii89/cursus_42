/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:34:26 by davifer2          #+#    #+#             */
/*   Updated: 2024/01/04 15:06:54 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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
	if (!store)
		return (NULL);
	if (*store == 0)
	{
		free(store);
		store = NULL;
	}
	return (store);
}

char	*read_extract_line(int fd, char *store, char *buffer, int *info)
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
			return (*info = 0, NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		temp = store;
		store = ft_strjoin(temp, buffer);
		free(temp);
		if (!store)
			return (*info = 0, NULL);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (store);
}

char	*cut_line(char *line, int *info)
{
	char	*nw_line;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	nw_line = ft_substr(line, 0, i);
	if (nw_line == NULL)
		return (*info = 0, free(line), NULL);
	free(line);
	return (nw_line);
}

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*line;
	char		*buffer;
	int			info;

	info = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
	return (NULL);
	if (!buffer)
		return (free(store[fd]), store[fd] = NULL, NULL);
	line = read_extract_line(fd, store[fd], buffer, &info);
	free(buffer);
	if (!info)
		return (store[fd] = NULL, NULL);
	buffer = NULL;
	if (!line)
		return (NULL);
	store[fd] = free_store(line);
	line = cut_line(line, &info);
	if (!info)
		return (free(store[fd]), store[fd] = NULL, NULL);
	return (line);
}
