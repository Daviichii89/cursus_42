// I need a program that reads a file and prints its content line by line.
//
// The program should be called like this:
// ./a.out file.txt
// And it should print the content of file.txt line by line.
//
// The file file.txt contains:
// Hello
// World
// This
// Is
// A
// Test

// The output should be:
// Hello
// World
// This
// Is

// The program should be able to read files of any size, and should not use more than 10 bytes of memory.

// The program should be written in C, and should be named get_next_line.c
// The function get_next_line should be declared like this:
// char *get_next_line(int fd, void *buffer, size_t size);
// The function should return a pointer to the line read, or NULL if there are no more lines to read.
// The function should read at most size - 1 bytes from the file descriptor fd, and store them in buffer.
// The line read should be null-terminated.
// The function should not use more than 10 bytes of memory.

// The function should be used like this:
// char buffer[10];
// char *line = get_next_line(fd, buffer, sizeof(buffer));

// The function should not use any global variables.

// The function should not use any external library.

// The function should not use any system call other than read.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *get_next_line(int fd, void *buffer, size_t size)
{
	char *string = (char *)buffer;
	int bytes_read = read(fd, string, size - 1);
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

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Uso: %s <nombre_archivo>\n", argv[0]);
		return 1;
	}

	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return 1;
	}

	char buffer[8];
	char *line = get_next_line(fd, buffer, sizeof(buffer));
	// print number of bytes read and the text of the actual line
	// int loops = 3;
	while (line != NULL)
	{
		printf("%s\n", line);
		// printf("Loop: %d\n%s\n", loops, line);
		line = get_next_line(fd, buffer, sizeof(buffer));
	}
	close(fd);
	return (0);
}

// gcc -Wall -Wextra -Werror get_next_line.c
