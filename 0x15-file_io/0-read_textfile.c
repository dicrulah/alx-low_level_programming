#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file and print to POSIX.
 * @filename: text file TO BE READ
 * @letters: number of letters that will be read
 * Return:  number of bytes read and printed
 *        '0' when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t text, fdoc, n;
	char *buffer;

	fdoc = open(filename, O_RDONLY);
	if (fdoc == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	text = read(fdoc, buffer, letters);
	n = write(STDOUT_FILENO, buffer, text);

	free(buffer);
	close(fdoc);
	return (n);
}
