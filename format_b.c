#include <stddef.h>
#include <stdlib.h>
#include "main.h"
/**
 * format_b - converts unsigned int to binary
 * @n: integer parameter
 * Return: length of binary number
 */
int format_b(int n)
{
	int i, len, var;
	float div, tmp = (n / 1);
	char *bin_o;

	if (n < 0)
	{
		n = -(n);
	}

	var = n;
	len = 0;
	do
	{
		n = (n / 2);
		len++;
	}
	while (n > 0);

	bin_o = malloc(sizeof(char) * len);
	i = len - 1;
	while (tmp != 0)
	{
		tmp /= 2;
		var /= 2;
		div = (tmp - var);
		if (div == 0.0)
		{
			bin_o[i] = 48;
			format_c(bin_o[i]);
		}
		else
		{
			tmp = (tmp - 0.5);
			bin_o[i] = 49;
			format_c(bin_o[i]);
		}
		i--;
	}
	free(bin_o);
	return (len);
}
