#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int recent;
	int index;
	int track = 0;

	for (index = 63; index >= 0; index--)
	{
		recent = n >> i;

		if (recent & 1)
		{
			track++;
			_putchar('1');
		}
		else if (track)
			_putchar('0');
	}
	if (!track)
		_putchar('0');
}

