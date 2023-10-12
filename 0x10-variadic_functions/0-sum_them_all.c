#include "variadic_functions.h"
#include <stdarg.h>
/**
 * sum_them_all - sum all the integer given
 * @n: the size of the variadic variable
 * Return: always sum of the number
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int i;

	va_list ap;

	va_start(ap, n);
	if (n == 0)
		return (0);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(ap, int);
	}
	va_end(ap);
	return (sum);
}
