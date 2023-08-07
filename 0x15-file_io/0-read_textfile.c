#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - Reads text file and prints to POSIX stdout
 * @filename: Pointer to name of file
 * @letters: The number of letters to be read and printed
 * Return: NULL if function fails or no filename or number of bytes
 * read or printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{

	int f;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);
	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(f);
		return (0);
	}
	bytes_read = read(f, buffer, letters);
	if (bytes_read == -1)
	{
		close(f);
		free(buffer);
		return (0);
	}
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(f);
		free(buffer);
		return (0);
	}
	free(buffer);
	close(f);
	return (bytes_written);
}
