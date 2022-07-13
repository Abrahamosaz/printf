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
	
	if (*(format - 1) == '%' && format == NULL)
	{
		format_c('%');
		return (0);
	}
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
 * check_switch - check for the specifiers used
 * @format: constant string
 * @args: adress of the argumnet passed to the function
 * Return: return integer value
 */
int check_switch(const char *format, va_list *args)
{
	int len, x;
	char *s;

	if (format == NULL)
		return (0);
	switch (*format)
	{
		case 'c':
		{
			x = va_arg(*args, int);
			len = format_c(x);
			break;
		}
		case 's':
		{
			s = va_arg(*args, char *);
			len = format_s(s);
			break;
		}
		case 'd':
		{
			x = va_arg(*args, int);
			len = format_d(x);
			break;
		}
		case 'i':
		{
			x = va_arg(*args, int);
			len = format_d(x);
			break;
		}
		case 'b':
		{
			x = va_arg(*args, int);
			len = format_b(x);
			break;
		}
		case 'u':
		{
			x = va_arg(*args, int);
			len = format_u(x);
			break;
		}
		case 'o':
		{
			x = va_arg(*args, int);
			len = format_o(x);
			break;
		}
		case 'X':
		{
			x = va_arg(*args, int);
			len = format_x(x, 1);
			break;
		}
		case 'x':
		{
			x = va_arg(*args, int);
			len = format_x(x, 0);
			break;
		}
		case 'r':
		{
			s = va_arg(*args, char *);
			len = rev_string(s);
			break;
		}
	}
	return (len);
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
			{
				x = format_c(*(format - 1));
				len = _putchar(format);
				len += x;
			}
			else
				len = check_switch(format, &args);
			count += len;
			state = 0;
		}
		format++;
	}
	va_end(args);
	return (count);
}
