#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*get_next_line(int fd, void *buffer, size_t size)
{
	char	*string;
	int		bytes_read;

	string = (char *)buffer;
	bytes_read = read(fd, string, size - 1);
	if (bytes_read <= 0)
	{
		if (bytes_read == 0)
			return (NULL);
		else
		{
			printf("Error al leer");
			return (NULL);
		}
	}
	string[bytes_read] = '\0';
	return (string);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Uso: %s <nombre_archivo>\n", argv[0]);
		return 1;
	}

	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return 1;
	}

	char buffer[10];
	char *line = get_next_line(fd, buffer, sizeof(buffer));
	// print number of bytes read and the text of the actual line
	printf("Line: %s\n", line);

	// int i = 1;
	// while (line != NULL)
	// {
	// 	// print number of bytes read and the text of the actual line
	// 	printf("Line %d: %s\n", i, line);

	// 	line = get_next_line(fd, buffer, sizeof(buffer));
	// 	i++;
	// }
	close(fd);
	return (0);
}*/
