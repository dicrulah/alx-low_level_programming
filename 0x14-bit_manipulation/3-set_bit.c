#include "main.h"

/**
 * sets the value of a bit to 1 at a given index
 * n is a pointer to the number
 * index to be set to 1
 *
 * return 1 for execution and -1 for not
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
