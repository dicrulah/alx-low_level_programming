#include "main.h"

/**
 * flip number to get from one number to another.
 * 1st number is n.
 * 2nd number is m.
 * return exchanged pattern.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	
	unsigned int counter = 0;
	unsigned long int number;
	unsigned long int exclusive = n ^ m;
	
	for (int k = 63; k >= 0; k--)
	{
		number = exclusive >> k;
		if (number & 1)
			counter++;
	}

	return (counter);
}
