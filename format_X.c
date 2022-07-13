#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * format_X - prints unsigned hexadecimal
 * @n: integer parameter
 * Return: number length
 */
int format_X(unsigned int n)
{
	size_t j, len, var, count, rem;
	char *std_o;

	var = n;
	count = 0;
	while (var)
	{
		var /= 16;
		count++;
	}
	len = count;
	std_o = malloc(sizeof(char) * len);
	j = count - 1;
	do {
		rem = n % 16;
		if (rem > 9)
		{
			std_o[j] = (rem + 55);
		} else
		{
			std_o[j] = (rem + 48);
		}
		n /= 16;
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
