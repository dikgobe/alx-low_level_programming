#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int track = 0;
	unsigned long int recent;
	unsigned long int important = n ^ m;
	int i;

	for (i = 63; i >= 0; i--)
	{
		recent = important >> i;
		if (recent & 1)
			track++;
	}

	return (track);
}
