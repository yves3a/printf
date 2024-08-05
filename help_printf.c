#include "main.h"
/**
 * cust_print - A helper function to implement custom formatted output.
 * @buffer: Pointer to the buffer where the formatted string is stored.
 * @format: The format string specifying how to format the output.
 * @args:The variable arguments to be formatted according to format string.
 *
 * Return: The total number of characters printed.
 * Returns -1 if an error occurs.
 */
int cust_print(string_buffer *buffer, const char *format, va_list args)
{
	int characters_printed, n_chars;
	format_specifier *spec = create_format_specifiers();
	/*Check if memory allocation for format specifiers was successful.*/
	if (spec == NULL)
		return (-1); /* when the memory fails*/

	characters_printed = n_chars = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if ((!_strchr("%ibducsSrRxXop", *format) && *(format + 1) == '\0')
					|| *format == '\0')
			{
				safe_free(spec);
				return (-1);/*Invalid format specifier or lone '%'. */
			}
			/*Process format modifiers (e.g., width, precision). */
			format = parse_modifiers(format, spec, args);
			if (format == NULL)
				return (-1);
			/* Process the specific format type and handle output. */
			n_chars = select_format_handler(*format, spec, args, buffer);
			characters_printed += n_chars;
		}
		else
		{
			append_char(buffer, *format);
			characters_printed++;
		}
		format++;
	}
	/* Output the formatted string to stdout. */
	print_str_buffer(buffer->data, characters_printed);
	/*Clean up allocated memory.*/
	safe_free(buffer->data);
	safe_free(spec);

	return (characters_printed);
}
