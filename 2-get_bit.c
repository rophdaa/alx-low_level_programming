#include <stdio.h>
#include "main.h"
/**
 * get_bit - Gets a value of a bit a given index
 * @n: The bit
 * @index: The index to get value from
 * Return: The value of bit at index or -1 to show otherwise
 */

int get_bit(unsigned long int n, unsigned int index)
{

	int val = -1;
	unsigned int i = 0;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	while (i <= index)
	{
		if (i == index)
			val = (n >> i) & 1;
		i++;
	}
	return (val);
}
