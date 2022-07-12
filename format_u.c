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
	size_t j, len, var, count;
	char *std_o;

	var = n;
	count = 0;
	do {
		var /= 10;
		count++;
	} while (var != 0);

	len = count;

	std_o = malloc(sizeof(char) * len);
	j = count - 1;
	do {
		std_o[j] = (n % 10) + 48;
		n /= 10;
		j--;
	} while (n != 0);

	j = 0;
	while (j < len)
	{
		format_c(std_o[j]);
		j++;
	}
	free(std_o);
	return (len);
}
