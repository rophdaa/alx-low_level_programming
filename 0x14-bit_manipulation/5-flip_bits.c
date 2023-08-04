#include <stdio.h>
#include "main.h"
/**
 * flip_bits - Counts umber of bits to be flipped to get through different #
 * @n: The number
 * @m: The number n should be flipped to
 * Return: The number of bits to be flipped
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{

	unsigned long int xor = n ^ m, bits = 0;

	while (xor > 0)
	{
		if ((xor & 1) == 1)
			bits++;
		xor >>= 1;
	}
	return (bits);
}
