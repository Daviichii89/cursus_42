/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:15:57 by davifer2          #+#    #+#             */
/*   Updated: 2024/02/23 20:22:57 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*read_content;
	int			read_bytes;
	static char	*read_buffer;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_content = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!read_content)
		return (NULL);
	while (!(ft_strchr(read_buffer, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, read_content, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			read_buffer = free_all(read_content, read_buffer);
			return (NULL);
		}
		*(read_content + read_bytes) = '\0';
		read_buffer = ft_strjoin(read_buffer, read_content);
	}
	free (read_content);
	read_content = read_line(read_buffer);
	read_buffer = create_substring(read_buffer);
	return (read_content);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("text.txt", 0_RDWR);
	if (fd < 0)
		return (1);
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || i > 80)
			break;
		printf("line %d: "%s", i++, line);
		free(line);
	}
	printf("line %d: %s", i++, line);
	close(fd);
	return (0);
}*/
