#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * copy_data - copies data from one file to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 *
 * Return: 0 on success, 98 or 99 on failure
 */
int copy_data(int fd_from, int fd_to)
{
	ssize_t r, w;
	char buffer[1024];

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
			return (99);
	}

	if (r == -1)
		return (98);

	return (0);
}

/**
 * close_files - closes two file descriptors
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 *
 * Return: 0 on success, 100 on failure
 */
int close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		close(fd_to);
		return (100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		return (100);
	}

	return (0);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, result;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		return (99);
	}

	result = copy_data(fd_from, fd_to);
	if (result != 0)
	{
		if (result == 98)
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
		else
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		close(fd_to);
		return (result);
	}

	return (close_files(fd_from, fd_to));
}
