#include"main.h"
/**
 * get_bit - a function which displays the index of the bit value
 * @n: the bit value
 * @index: the index of the bit value
 * Return: index value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	return ((n >> index) & 1);
}
