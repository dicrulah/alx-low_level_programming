#include "main.h"
#include <stdlib.h>

/**
 * reads a text file and prints it to the POSIX standard output
 * @filename: text file being read
 * @letters: number of letters to be read
 * returns the actual number of letters it could read and print,if filename is NULL and write fails return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buffer;
    ssize_t filedescriptor, bWrite, bRead;

    filedescriptor = open(filename, O_RDONLY);
    if (filedescriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    bRead = read(filedescriptor, buffer, letters);
    bWrite = write(STDOUT_FILENO, buffer, bRead);

    free(buffer);
    close(filedescriptor);
    return (bWrite);
}
