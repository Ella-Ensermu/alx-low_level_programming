#include "main.h"
#include<string.h>
/**
 * create_file - a function that creates a file.
 * @filename: the name of a file to create
 * @text_content: the content of the file
 * Return: 1 on success -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, fd2, len = 0;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);
	if (text_content != NULL)
	{
		len = strlen(text_content);
		for (len = 0; text_content[len];)
			len++;
	}
	fd2 = write(fd, text_content, len);
	if (fd == -1 || fd2 == -1)
		return (-1);

	close(fd);
	return (1);
}
