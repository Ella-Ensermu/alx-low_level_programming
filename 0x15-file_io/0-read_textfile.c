#include "main.h"
/**
 * read_textfile - reads a text file and prints it
 * to the POSIX standard output
 * @filename:it represents the poiner to the name of the file
 * @letters: number of letters
 * Return: 0 if filename os NULL, if the file canno be opened
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, byte_read, byte_written;
	char *buf;

	if (filename == NULL)
		return (0);
	buf = malloc(letters);
	if (buf == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}
	byte_read = read(fd, buf, letters);
	byte_written = write(STDOUT_FILENO, buf, byte_read);
	if (byte_read == -1 || byte_written == -1 || byte_read != byte_written)
	{
		free(buf);
		return (0);
	}
	free(buf);
	close(fd);
	return ((byte_written == byte_read) ? byte_read : 0);
}
