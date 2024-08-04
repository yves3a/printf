#include "main.h"

/**
 * s_print - it prints the string
 * @args: an arguments of a string to be outputed
 * Return: number of charcters to be printed
 */

int s_print(va_list args)
{
	char *string = va_arg(args, char*);
	int num_char = 0, output;

	/* when the sting is NULL */
	if (!string)
	{
		string = "(null)";
	}
	/* determining the number of characters to be printed */

	while (*string)
	{
		output = _putchar(*string);
		if (output == -1)
			return (-1);
		num_char++;
		string++;
	}

	return (num_char);
}
