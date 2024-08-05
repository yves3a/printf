#include "main.h"

/**
 * select_format_handler - Chooses the correct
 * handler function for a given format specifier.
 * @specifier: The format specifier character to handle.
 * @spec: Pointer to an array of format specifier structures.
 * @args: Variable argument list.
 * @buffer: Pointer to the string_buffer structure where output is stored.
 *
 * Description: This function iterates through the array of format specifiers
 * to find a match for the provided specifier. Once a match is found, it sets
 * the relevant flags and width based on the format specifier.
 * The function then
 * calls the appropriate handler function to process the specifier. If no match
 * is found, it appends the specifier to the buffer for further handling.
 *
 * Return: The number of characters added to the buffer
 * for the format specifier,
 * or the number of characters added for an unknown specifier.
 */
int select_format_handler(const char specifier, format_specifier *spec,
						  va_list args, string_buffer *buffer)
{
	int i, characters_added;
	size_t initial_length = buffer->length;

	for (i = 0; spec[i].specifier != '\0'; i++)
	{
		/*  Check if the current specifier matches the provided specifier */
		if (spec[i].specifier == specifier)
		{
			if (spec->plus_flag && is_valid_plus_specifier(specifier))
				spec[i].plus_flag = 1;
			if (spec->space_flag && is_valid_space_specifier(specifier))
				spec[i].space_flag = 1;
			if (spec->sharp_flag && is_valid_sharp_specifier(specifier))
				spec[i].sharp_flag = 1;
			if (spec->zero_flag && is_valid_zero_specifier(specifier))
				spec[i].zero_flag = 1;
			if (spec->width && is_valid_width_specifier(specifier))
				spec[i].width = spec->width;
			if (spec->minus_flag && is_valid_width_specifier(specifier))
				spec[i].minus_flag = 1;
			if (spec->precision && is_valid_width_specifier(specifier))
				spec[i].precision = spec->precision;
			if (spec->length && is_valid_length_specifier(specifier))
				spec[i].length = spec->length;

			/* Call the handler function associated with the specifier */
			return (spec[i].handler(&spec[i], args, buffer));
		}
	}
	append_char(buffer, '%');
	append_char(buffer, specifier);

	characters_added = buffer->length - initial_length;
	return (characters_added);
}
