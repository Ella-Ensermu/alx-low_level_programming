#include "main.h"
/**
 * print_binary - a function that converts a binary number to decimal
 * @n: a decimal value
 * Return: null
 */
void print_binary(unsigned long int n)
{
	int i, zero = 1;
	unsigned long int m;
	int f;

	f = sizeof(unsigned long int) * 8 - 1;

	for (i = f; i >= 0; i--)
	{
		m = 1UL << i;
		if (n & m)
		{
			_putchar('1');
			zero = 0;
		}
		else if (!zero)
		{
			_putchar('0');
	}
		m >>= 1;
	}

	if (zero)
	{
		_putchar('0');
	}

}
