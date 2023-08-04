#include <stdio.h>
#include "main.h"
/**
 * clear_bit - Sets value of bit to 0 at a given index
 * @n: Pointer to bit
 * @index: Index to set value at
 * Return: 1 if successful -1 if there is an error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{

	unsigned int i = 0;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	while (i <= index)
	{
		if (i == index)
			*n &= ~(1 << i);
		i++;
	}
	return (1);
}
