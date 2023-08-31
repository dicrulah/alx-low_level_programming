#include "main.h"

/**
 * returns the value of a bit at a given index.
 * n is the number to search
 * 
 *
 * return the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (n >> index) & 1;

	return (bit_val);
}
