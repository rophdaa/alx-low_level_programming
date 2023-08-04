#include <stdio.h>
#include "main.h"
/**
 * set_bit - Sets value of bit to 1 at a given index
 * @n: Pointer
 * @index: The index to set value at
 * Return: 1 if successful -1 if there is an error
 */

int set_bit(unsigned long int *n, unsigned int index)
{

	unsigned int i = 0;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	while (i <= index)
	{
		if (i == index)
			*n |= (1 << i);
		i++;
	}
	return (1);
}
