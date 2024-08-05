#include "main.h"
/**
 * parse_modifiers - Processes format modifiers in a format string.
 * @format: Pointer to the current position in the format string.
 * @spec: Pointer to the structure where format specifiers are stored.
 * @args: List of variable arguments to be used for width or precision.
 *
 * This function iterates over the format string, updating the format_specifier
 * structure with flags, width, precision, and length based on the modifiers
 * found. It stops parsing when a conversion specifier is reached or an
 * unknown character is encountered.
 *
 * Return: Pointer to the position in
 * the format string after processing modifiers.
 */
const char *parse_modifiers(const char *format, format_specifier *spec,
	va_list args)
{
	/* Loop through the format string until a conversion specifier is found */
	while (*format && !str_chr("%bidcsSrRxXuop", *format))
	{
		/* Check for '0' flag and update width */
		if (*format == '0')
		{
			spec->zero_flag = 1;
			spec->width = get_width_precision(format + 1, args);
			format = update_format(format);
		}
		/* Check for precision specifier */
		else if (*format == '.')
		{
			spec->precision = get_width_precision(format + 1, args);
			format = update_format(format + 1);
		}
		/* Check for numeric width specifier */
		else if (*format >= '1' && *format <= '9')
		{
			spec->width = get_width_precision(format, args);
			format = update_format(format);
		}
		/* Check for '-' flag */
		else if (*format == '-')
		{
			spec->minus_flag = 1;
		}
		/* Check for '*' flag for width */
		else if (*format == '*')
		{
			spec->width = get_width_precision(format, args);
		}
		/* Check for '#' flag */
		else if (*format == '#')
		{
			spec->sharp_flag = 1;
		}
		/* Check for '+' flag */
		else if (*format == '+')
		{
			spec->plus_flag = 1;
		}
		/* Check for space flag */
		else if (*format == ' ')
		{
			spec->space_flag = 1;
		}
		/* Check for length modifiers */
		else if (*format == 'l' || *format == 'h')
		{
			spec->length = *format;
		}
		else
		{
			return (format); /* Return if an unknown modifier is encountered */
		}
		format++; /* Move to the next character in the format string */
	}
	return (format);
}
/**
 * update_format - Skips digits and asterisks in the format string.
 * @format: Pointer to the current position in the format string.
 *
 * This function advances the format pointer past any digits and
 * asterisks, which are used to specify width and precision.
 *
 * Return: Pointer to the last non-digit, non-asterisk character processed.
 */
const char *update_format(const char *format)
{
	while (isdigit(*format) || *format == '*')
		format++;
	return (format - 1);
}
/**
 * get_width_precision - Retrieves the width or precision from the format string.
 * @format: Pointer to the format string position to parse.
 * @args: List of variable arguments to obtain width/precision if specified as '*'.
 * This function extracts an integer value for width or precision from the
 * format string. If the value is specified as '*', it retrieves the value
 * from the argument list.
 *
 * Return: The integer value of width or precision.
 */
int get_width_precision(const char *format, va_list args)
{
	if (isdigit(*(format)))
	{
		return (_atoi(format));/*Convert numeric characters to an integer*/
	}
	else if (*format == '*')
	{
		return (va_arg(args, int));/*Retrieve width/precision from arguments*/
	}
	return (0);
}
