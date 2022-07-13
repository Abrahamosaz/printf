#include <stddef.h>
#include <stdlib.h>
#include "main.h"
/**
 * format_b - converts unsigned int to binary
 * @n: integer parameter
 * Return: output length
 */
int format_b(unsigned int n)
{
	long int bin, rem, pval, var, len;

	pval = 1;
	bin = 0;
	while (n)
	{
		rem = n % 2;
		n /= 2;
		bin += (rem * pval);
		pval *= 10;
	}
	format_d(bin);
	var = bin;
	len = 0;
	do {
		var /= 10;
		len++;
	} while (var != 0);
	return (len);
}
