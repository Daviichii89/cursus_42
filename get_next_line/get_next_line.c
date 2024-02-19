#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *		read_content;
	int		read_bytes;
	static char *	read_buffer;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	read_content = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!read_content)
		return(NULL);
	while (!(ft_strchr(read_buffer, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, read_content, BUFFER_SIZE);
		if (read_bytes = -1)
		{
			read_buffer = free-all(read_content, read_buffer);
			return (NULL);
		}
		*(read_content + read_bytes) = '\0';
		read_buffer = ft_strjoin(read_buffer, read_content);
	}
	free(read_content);
	read_content = read_line(read_buffer);
	read_buffer = create_substring(read_buffer);
	return (read_content);	
}

int	main(void)
{
	get_next_line();
}
