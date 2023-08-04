#include <stdio.h>
#include "main.h"
/**
 * get_endianness - Checks the endianness
 *
 * Return: 0 if big endian or 1 if little endian
 */

int get_endianness(void)
{

	int n = 1;
	char *endian = (char *)&n;
	size_t i = 0;

	while (i < sizeof(int))
	{
		if (endian[i] == 1)
			return (1);
		i++;
	}
	return (0);
}
