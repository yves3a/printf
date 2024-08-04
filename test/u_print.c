#include "main.h"

/**
 * u_print - it prints an unsigned int
 * @args: arguments that are passed in printf function
 *
 * Return: number of chars printed otherwise -1
 */

int u_print(va_list args)
{
	unsigned int numb = va_arg(args, unsigned int), dig = numb;
	int num_char = 0, output;


	/* if the number is equal or less than to 0 */

	if (numb < 1)
	{
		_putchar('0');
		return (1);
	}
	output =  print_number(numb);

	/* determining number of characters */

	if (output == 1)
	{
		num_char += countDigits(dig);
	}
	else
		num_char = -1;
	return (num_char);
}
