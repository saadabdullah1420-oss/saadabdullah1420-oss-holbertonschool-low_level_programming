#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file and writes text to it
 * @filename: name of the file
 * @text_content: text to write
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len;
	ssize_t written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len] != '\0'; len++)
			;

		written = write(fd, text_content, len);
		if (written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
