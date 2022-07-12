#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * _printf - printf  function that print to standard output
 * @format: The string format specifier
 *
 *Description: print the required result to standard output
 * with the specified format specifiers
 *
 * Return: return the length of the string format specifier
 */
int _printf(const char *format, ...)
{
	va_list args;
	size_t x, state, count, len;
	char *s;

	va_start(args, format);
	state = count = len = 0;
	while (*format)
	{
		if (state == 0)
		{
			if (*format != '%')
			{
				format_c(*format);
				count++;
			} else
			{
				state = 1;
			}
		} else
		{
			if (*format == '%')
				len = format_c('%');
			switch (*format)
			{
				case 'c':
				{
					x = va_arg(args, int);
					len = format_c(x);
					break;
				}
				case 's':
				{
					s = va_arg(args, char *);
					len = format_s(s);
					break;
				}
				case 'd':
			 	{
					x = va_arg(args, int);
					len = format_d(x);
					break;
				}
				case 'i':
				{
					x = va_arg(args, int);
					len = format_d(x);
					break;
				}
				case 'b':
				{
					x = va_arg(args, int);
					len = format_b(x);
					break;
				}
				case 'u':
				{
					x = va_arg(args, int);
					len = format_u(x);
					break;
				}
				default: {
					break;
				}
			}
			count += len;
			state = 0;
		}
		format++;
	}
	va_end(args);
	return (count);
}
