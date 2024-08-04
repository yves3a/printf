#include "main.h"

/**
 * c_print - it prints the character
 * @args: argument to be passed to the format.
 * Return: number of characters to be printed, otherwise NULL
 */

int c_print(va_list args)
{
	char b = va_arg(args, int);
	int output, num_char = 0;

	output = _putchar(b);
	if (output == -1)
	{
		return (-1);
	}
	num_char++;

	return (num_char);
}
