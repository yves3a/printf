#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - it prints the number of characters to be printed to the console.
 * @format: string format to be printed
 * Return: the number of printed characters
 *-1 when the invalid format is passed.
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;
	int (*ptr)(va_list) = NULL;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) !=  '%')
		{
			format++;
			ptr = get_char(format);
			if (*format == '\0')
			{
				return (-1);
			}
			else if (ptr == NULL)
			{
				_putchar('%');
				_putchar(*format);
				char_count = char_count + 2;
			}
			else
			{
				char_count += ptr(args);
			}
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			format++;
			_putchar('%');
			char_count = char_count + 1;
		}
		else
		_putchar(*format);
		char_count++;
		format++;
	}
	va_end(args);
	return (char_count);
}
