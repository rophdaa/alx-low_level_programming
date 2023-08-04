#include <stdio.h>
#include "main.h"
/**
 * print_binary - Shows binary representation of a digit
 * @n: The digit to be shown in binary
 */

void print_binary(unsigned long int n)
{

	int i;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	for (i = (sizeof(unsigned long int) * 8) - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
			break;
	}
	for (; i >= 0; i--)
	{
		if ((n >> i) & 1)
			_putchar('1');
		else
			_putchar('0');
	}
}
