#include "main.h"

/**
 * handle_width - Handles the width specifier for formatted output.
 * @spec: Pointer to the format specifier structure containing the width.
 * @buffer: Pointer to the string buffer where output is stored.
 * @len: Length of the string to be formatted.
 *
 * This function adds padding to the output buffer based on the specified width
 * and the flags set in the format specifier. If the zero flag is set and the
 * minus flag is not set, it pads with zeros; otherwise, it pads with spaces.
 *
 * Return: The number of characters added to the buffer for padding.
 */
int handle_width(format_specifier *spec, string_buffer *buffer, int len)
{
	int characters_added = 0;
	size_t initial_length = buffer->length;

	/* Append padding to the output buffer based on width specifier */
	while (spec->width > len)
	{
		if (spec->zero_flag && !spec->minus_flag)
		{
			append_char(buffer, '0'); /* Pad with zeros if zero flag is set */
		}
		else
		{
			append_char(buffer, ' '); /* Pad with spaces otherwise */
		}
		spec->width--;
	}

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
