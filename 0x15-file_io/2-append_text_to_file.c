#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"
/**
 * append_text_to_file - Append text at end of file
 * @filename: Pointer to name of file
 * @text_content: String to include at end of file
 * Return: -1 if filename is NULL or function fails
 * 1 for otherwise
 */

int append_text_to_file(const char *filename, char *text_content)
{

	int fd = open(filename, O_WRONLY | O_APPEND);

	if (filename == NULL)
	{
		return (-1);
	}
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		ssize_t bytes_written = write(fd, text_content, strlen(text_content));
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
