#include "main.h"

/**
 * sets the value of a bit to 0 at a given index.
 * n is the pointer to the number.
 * index clears the bit
 *
 * return for successful execution and -1 otherwise
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
