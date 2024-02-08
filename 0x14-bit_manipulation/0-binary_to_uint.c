#include "main.h"
/**
 * binary_to_uint - a function that converts a binary number to decimal
 * @b: binary value to be converted to a decimal
 * Return: a decimal number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal = 0, i = 1;

	if (b == NULL)
		return (0);
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		decimal <<= 1;
		if (b[i] == '1')
			decimal += 1;
	}
	return (decimal);
}
