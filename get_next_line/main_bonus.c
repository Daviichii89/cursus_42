#include "get_next_line_bonus.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }

    int fd;
	int fd2;
    char *line;
	char *line2;
    int count;

    count = 0;
    fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
    if (fd == -1 || fd2 == -1)
    {
        printf("Error opening file");
        return 1;
    }
    while (1)
    {
        line = get_next_line(fd);
		line2 = get_next_line(fd2);
        if (line == NULL || line2 == NULL)
            break;
        count++;
        printf("Line %d: %s\n", count, line);
		printf("Line2 %d: %s\n", count, line2);
        free(line);
		free(line2);
        line = NULL;
		line2 = NULL;
    }
    close(fd);
	close(fd2);
    return (0);
}
