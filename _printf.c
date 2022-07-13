#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
 * check_f - check the format value if its part of the specifiers
 * @format: format passed to the function
 * Return: return (0 if True) 1 otherwise
 */
int check_f(const char *format)
{
	const char *spec = "rbdicuxXos";
	int i = 0;

	while (spec[i] != '\0')
	{
		if (*format == spec[i])
			return (0);
		i++;
	}
	return (1);
}
/**
 * _putchar - print out the character value
 * @format: format passed to the function
 * Return: return 1
 */
int _putchar(const char *format)
{
	char c = *format;

	write(1, &c, 1);
	return (1);
}
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
			if (check_f(format))
				len = _putchar(format);
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
				case 'o':
				{
					x = va_arg(args, int);
					len = format_o(x);
					break;
				}
				case 'X':
				{
					x = va_arg(args, int);
					len = format_X(x);
					break;
				}
				case 'x':
				{
					x = va_arg(args, int);
					len = format_x(x);
					break;
				}
				case 'r':
				{
					s = va_arg(args, char *);
					len = rev_string(s);
					break;
				}
				default:
				{
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
