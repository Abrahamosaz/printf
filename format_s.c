#include "main.h"
#include <unistd.h>
/**
 * format_s - Prints string to standard output
 * @str: string parameter
 * Return: length of string
 */
int format_s(char *str)
{
	int len, i, j;

	i = len = 0;
	while (str[i++] != '\0')
	{
		len++;
	}
	j = 0;
	while (j < len)
	{
		write(1, &str[j], 1);
		j++;
	}
	return (len);
}
