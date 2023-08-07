#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"
/**
 * create_file - Create a file
 * @filename: Pointer to name of file to be created
 * @text_content: Pointer to string to be included in file
 * Return: -1 if function fails and 1 if otherwise
 */

int create_file(const char *filename, char *text_content)
{

	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	w = write(fd, text_content, len);
	while (w == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
