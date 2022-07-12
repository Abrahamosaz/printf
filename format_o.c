#include <stddef.h>
#include <stdlib.h>
#include "main.h"
/**
 * format_o - converts unsigned int to octal
 * @n: integer parameter
 * Return: output length
 */
int format_o(unsigned int n)
{
	int pval, rem, oct, len, var;

	pval = 1;
	oct = 0;
	while (n)
	{
		rem = n % 8;
		oct += (rem * pval);
		n /= 8;
		pval *= 10;
	}

	var = oct;
	len = 0;
	do {
		var /= 10;
		len++;
	} while (var != 0);
	format_d(oct);
	return (len);
}
