#include "get_next_line.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }

	int i;
    int fd;
	int fd2;
    char *line;
	char *line2;

	i = 0;
    fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return 1;
    }
    while (i++ <= 8)
    {
        line = get_next_line(fd);
		line2 = get_next_line(fd2);
        printf("Line %d: %s\n", i, line);
		printf("Line2 %d: %s\n", i, line2);
        free(line);
		free(line2);
        line = NULL;
		line2 = NULL;
    }
    close(fd);
	close(fd2);
    return (0);
}

// gcc -Wall -Wextra -Werror get_next_line.c
