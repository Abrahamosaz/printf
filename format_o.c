#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * format_o - converts unsigned int to octal
 * @n: integer parameter
 * Return: output length
 */
int format_o(unsigned int n)
{
	unsigned int pval, rem, oct, len, var;

	pval = 1;
	oct = 0;
	while (n)
	{
		rem = n % 8;
		oct = oct + (rem * pval);
		n = n / 8;
		pval = pval * 10;
	}
	printf("\n%d\n", oct);
	format_u(oct);

	var = oct;
	len = 0;
	do {
		var /= 10;
		len++;
	} while (var != 0);
	return (len);
}
