#include "main.h"
#include <unistd.h>
/**
 * format_c - Prints character to standard output
 * @ch: character parameter
 * Return: 1
 */
int format_c(char ch)
{
	write(1, &ch, 1);
	return (1);
}
