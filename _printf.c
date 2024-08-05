#include "main.h"

/**
 * _printf - Outputs a formatted string to the standard output.
 * @format: The string that specifies the format.
 *
 * Return: he total number of characters printed,
 * or -1 if the format string is NULL.
 */


int _printf(const char *format, ...)
{
	int count_char;
	string_buffer buf;
	va_list args;

	/*If the format string is NULL, return an error.*/
	if (format == NULL)
		return (-1);

	va_start(args, format);/*Begin processing variable arguments.*/

	/*Prepare the buffer to collect the formatted output.*/
	string_buffer_init(&buf);

	/* Process the format string and arguments, storing the result in the buffer,*/
	/*and count the characters to be printed.*/
	count_char = cust_print(&buf, format, args);

	va_end(args);/*Clean up the argument list.*/
	return (count_char);
}
