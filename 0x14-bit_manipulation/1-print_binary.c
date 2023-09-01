#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;

	if (n == 0)
		exit(0);

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			write(1, "1", 1);
			count++;
		}
		else if (count)
			write(1, "0", 1);
	}
	if (!count)
		write(1, "0", 1);
}
