#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer
 * @file: Name the file buffer is storing bytes for
 * Return: Pointer to the newly allocated buffer
 */

char *create_buffer(char *file)
{

	char *buffer;
	int bufferSize = 1024;
	int allocationSize = sizeof(char) * bufferSize;

	buffer = malloc(allocationSize);
	while (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - Closes file
 * @fd: File descriptor to be closed
 */

void close_file(int fd)
{

	int c;

	c = close(fd);
	for (; c == -1; c = close(fd))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(99);
	}
}

/**
 * main - Copies content of one file to another
 * @argc: The number of arguments in the program
 * @argv: Array of pointers to arguments
 * Return: 0 if successful and error if otherwise
 * Description: If the argument count is wrong - exit code 97.
 * If file_from is unavailable or unreadable - exit code 98.
 * If file_to cannot create or write into file - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */

int main(int argc, char *argv[])
{

	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		while (1)
		{
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			exit(97);
		}
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (r == -1 || from == -1)
		{
			while (1)
			{
				dprintf(STDERR_FILENO,
						"Error: Can't read from file %s\n", argv[1]);
				free(buffer);
				exit(98);
			}
		}
		w = write(to, buffer, r);
		if (w == -1 || to == -1)
		{
			while (1)
			{
				dprintf(STDERR_FILENO,
						"Error: Can't write to %s\n", argv[2]);
				free(buffer);
				exit(99);
			}
		}
		r = read(from, buffer, 1024);
		to = open(argv[2], O_APPEND | O_WRONLY);
	} while (r > 0);
	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}
