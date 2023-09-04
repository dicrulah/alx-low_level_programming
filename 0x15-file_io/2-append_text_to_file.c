#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

/**
 * append_text_to_file - writes text at the end of a file.
 * @filename: the file pointer
 * @text_content: string attached to the end of file
 *
 * Return: If function fails or filename is NULL then -1.
 *         If the file does not exist the user cannot write = -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, n, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	n = write(o, text_content, length);

	if (o == -1 || n == -1)
		return (-1);

	close(o);
	return (1);
}
