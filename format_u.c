#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * format_u - prints unsigned integers
 * @n: integer parameter
 * Return: number length
 */
int format_u(unsigned int n)
{
	size_t len, var, count;

	var = n;
	count = 0;
	do {
		var /= 10;
		count++;
	} while (var != 0);

	len = count;
	format_d(n);
	return (len);
}
