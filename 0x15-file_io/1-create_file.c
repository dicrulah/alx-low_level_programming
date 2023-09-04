#include "main.h"

/**
 * create_file - this will create a file.
 * @filename: A pointer to the file to be created
 * @text_content: string pointer to the file.
 *
 * Return: -1 if the function to create file fails.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fdoc, n, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}
	fdoc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	n = write(fdoc, text_content, length);

	if (fdoc == -1 || n == -1)
		return (-1);

	close(fdoc);
	return (1);
}
