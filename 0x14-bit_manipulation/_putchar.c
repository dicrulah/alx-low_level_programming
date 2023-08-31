#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to standard output
 * c is the character to print
 *
 * return 1
 * -1 return if there is an error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
