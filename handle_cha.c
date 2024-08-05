#include "main.h"

/**
 * handle_char - Appends a character to the string buffer.
 * @spec: Pointer to the format specifier structure.
 * @args: List of arguments from which the character is obtained.
 * @buffer: String buffer where the character is appended.
 *
 * This function retrieves a character from the variable argument list and
 * appends it to the provided string buffer. If a width is specified in the
 * format specifier and the minus flag is not set, it adds space padding before
 * the character. If the minus flag is set,
 * padding is added after the character.
 *
 * Return: The number of characters added to the string buffer (always 1).
 */
int handle_char(const format_specifier *spec, va_list args,
	string_buffer *buffer)
{
	int characters_added;
	size_t initial_length;
	char ch = va_arg(args, int);

	initial_length = buffer->length;

	/*
	 * Add space padding before the character if
	 * width is specified and minus flag is not set
	 */
	if (spec->width && !spec->minus_flag)
	{
		handle_width((format_specifier *)spec, buffer, 1);
	}

	append_char(buffer, ch); /* Append the character to the buffer */

	/* Add space padding after the character if the minus flag is set */
	if (spec->minus_flag)
	{
		handle_width((format_specifier *)spec, buffer, 1);
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}

/**
 * handle_percent - Appends a percent character '%' to the string buffer.
 * @spec: Pointer to the format specifier structure (unused).
 * @args: List of arguments (unused).
 * @buffer: String buffer where the percent character is appended.
 *
 * This function appends a percent character '%' to the provided string buffer.
 * The format specifier and argument list are unused in this function as no
 * additional formatting is needed for the percent character.
 *
 * Return: Always returns 1, indicating one character was appended.
 */
int handle_percent(__attribute__((unused)) const format_specifier *spec,
	__attribute__((unused)) va_list args, string_buffer *buffer)
{
	append_char(buffer, '%'); /* Append the percent character to the buffer */

	return (1);
}
