#include "main.h"

/**
 * o_print - it prints octal number from decimal number.
 * @args: the number passed by the user to be printed
 *
 * Return: the number of charcters that are printed
 */

int o_print(va_list args)
{
	unsigned int Num_dec = va_arg(args, unsigned int), rem;
	int num_char = 0, i = 1, output;

	char *string;

	num_char += countOctal(Num_dec);

	/* allocating dynamic memory*/

	string = malloc(sizeof(char) * (num_char + 1));
	if (string == NULL)
		return (-1);
	/* iterating through the number */

	for (i = 1; i < num_char + 1; i++)
	{
		rem = Num_dec % 8;
		Num_dec = Num_dec / 8;
		string[num_char - i] = rem + '0';
	}
	for (i = 0; i < num_char; i++)
	{
		output = _putchar(string[i]);
		if (output == -1)
		{
			free(string);
			return (-1);
		}
	}
	free(string);
	return (-1);
}
