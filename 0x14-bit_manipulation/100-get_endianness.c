#include "main.h"

/**
 * get the end digit in the memory location
 * return 0 for big and 1 for small
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
