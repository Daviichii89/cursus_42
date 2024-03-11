#include "get_next_line.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }

    int fd;
    char *line;
    int count;

    count = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return 1;
    }
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        count++;
        printf("Line %d: %s\n", count, line);
        free(line);
        line = NULL;
    }
    close(fd);
    return (0);
}

// gcc -Wall -Wextra -Werror get_next_line.c
