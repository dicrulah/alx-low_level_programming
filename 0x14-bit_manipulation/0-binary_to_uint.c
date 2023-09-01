#include "main.h"
#include <stddef.h>

/**
 * binary_to_unit - convert binary to unsigned int.
 * the string containing the binary number is b.
 *
 * it returns the converted number.
 */

/*Prototype of the function*/
unsigned int binary_to_uint(const char *b)
{
	unsigned int binary_to_decimal = 0;
	int n = 0;

	if (b == NULL)
		return (0);

	while (b[n] != '\0')
	{
		if (b[n] < '0' || b[n] > '1')
			return (0);
		binary_to_decimal = 2 * binary_to_decimal + (b[n] - '0');
		}
	/*Return the result*/
	return (binary_to_decimal);
}
