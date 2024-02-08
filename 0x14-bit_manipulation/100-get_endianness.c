#include "main.h"
/**
 * get_endianness - it is a function used to identify the endianness
 * Return: return 0  if it is big endian and 1 if it is little endian
 */
int get_endianness(void)
{
	int num = 1;
	char *ptr = (char *)&num;

	return (*ptr == 1);
}
