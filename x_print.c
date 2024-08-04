#include "main.h"

/**
 * lowerHex_print - it converts an integer in hexadecimal and print it
 * @numb: number to be printed printed
 * @num_bytes: pointer to the number of bytes printed
 *
 * Return: void
 */

void lowerHex_print(unsigned int numb, int *num_bytes)
{
	int wow;

	/*Recursively process higher-order digits first */
	/* if the number is greater than 15.*/

	if (numb > 15)
		lowerHex_print(numb >> 4, num_bytes);

	/*stops processing when error occurred during printing */

	if (*num_bytes == -1)
		return;
	/* Determine the character to print based on the last 4 bits. */

	if ((numb & 15) < 10)
		wow = _putchar('0' + (numb & 15));
	else
		wow = _putchar('a' + (numb & 15) % 10);

	/* update number of bytes or flag an error */

	if (wow == -1)
		*num_bytes = -1;
	else
		*num_bytes += wow;
}

/**
 * x_print - it printss an integer in a lowercase decimal
 * @args: integer to get printed as a current element
 *
 * Return: number of bytes
 */
int x_print(va_list args)
{
	int count = 0;

	/* retrieve number from argument and print it in */
	 /* lower case */

	lowerHex_print(va_arg(args, int), &count);

	return (count);
}
