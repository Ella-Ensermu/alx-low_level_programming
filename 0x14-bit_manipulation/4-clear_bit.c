#include "main.h"
/**
 * clear_bit - a fuction whicn sets the value of a bit to 0
 * @n: bit value
 * @index: index the bit to be changed
 * Return: 1 = success and -1 = error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	*n &= ~(1UL << index);
	return (1);
}
