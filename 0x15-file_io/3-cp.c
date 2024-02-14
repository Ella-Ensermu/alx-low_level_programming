#include"main.h"

/**
 * cp - a function which copies a file content to another file
 * @file_form: source file
 * @file_to: function which file is copied to
 * Return: -1 on failure and 1 on success
 */
void cp(char *file_form, char *file_to)
{
	int fd_read, fd_write;
	ssize_t n_read, n_written;
	char **buf;

	buf = malloc(sizeof(char *) * 1024);
	if (buf == NULL)
	{
		perror("Error: memory allocation failed");
		exit(EXIT_FAILURE);
	}

	fd_read = open(file_form, O_RDONLY);
	if (fd_read == -1)
	{

