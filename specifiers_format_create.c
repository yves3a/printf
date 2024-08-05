#include "main.h"
/**
 * create_format_specifiers - Generates an array of
 * format specifier structures.
 * Description: This function initializes and allocates memory for an array
 * of format specifier structures. Each structure contains information about
 * a specific format type and its corresponding handler function. The function
 * returns a pointer to the newly created array. If memory allocation fails,
 * it returns NULL. The allocated memory must be freed using safe_free() to
 * prevent memory leaks.
 *
 * Return: A pointer to an array of format specifier structures, or NULL if
 * memory allocation fails.
 */
format_specifier *create_format_specifiers(void)
{
	static format_specifier specifiers[] = {
		{'d', 0, 0, 0, 0, 0, 0, 0, 0, handle_decimal},
		{'i', 0, 0, 0, 0, 0, 0, 0, 0, handle_decimal},
		{'c', 0, 0, 0, 0, 0, 0, 0, 0, handle_char},
		{'%', 0, 0, 0, 0, 0, 0, 0, 0, handle_percent},
		{'s', 0, 0, 0, 0, 0, 0, 0, 0, handle_string},
		{'S', 0, 0, 0, 0, 0, 0, 0, 0, handle_custom_string},
		{'r', 0, 0, 0, 0, 0, 0, 0, 0, handle_string_reversal},
		{'R', 0, 0, 0, 0, 0, 0, 0, 0, handle_rot13},
		{'x', 0, 0, 0, 0, 0, 0, 0, 0, handle_hex_lower},
		{'X', 0, 0, 0, 0, 0, 0, 0, 0, handle_hex_upper},
		{'b', 0, 0, 0, 0, 0, 0, 0, 0, handle_binary},
		{'o', 0, 0, 0, 0, 0, 0, 0, 0, handle_octal},
		{'u', 0, 0, 0, 0, 0, 0, 0, 0, handle_unsigned_int},
		{'p', 0, 0, 0, 0, 0, 0, 0, 0, handle_pointer},
	};

	/*Determine the total number of format specifiers. */
	size_t num_specifiers = sizeof(specifiers) / sizeof(specifiers[0]);

	/* Allocate memory for the array of format specifier structures. */
	format_specifier *format_specifiers = malloc(
			num_specifiers * sizeof(format_specifier));

	/*Check if the memory allocation was successful. */
	if (format_specifiers == NULL)
	{
		return (NULL);
	}

	_memcpy(
			format_specifiers, specifiers, num_specifiers * sizeof(format_specifier));

	return (format_specifiers);
}
