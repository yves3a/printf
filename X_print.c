#include "main.h"

/**
 * upperHex_print - it prints and convert integer in hex
 * @numb: number to print
 * @num_bytes: pointer to count number of bytes
 *
 * Return:void
 */
void upperHex_print(unsigned int numb, int *num_bytes)
{
	int wow;

	/*If the number is greater than 15, continue dividing it by 16 */
	/* recursively call the function to print the higher-order digits first. */

	if (numb > 15)
		upperHex_print(numb >> 4, num_bytes);

	/* If num_bytes has been set to -1, an error*/
	/* occurred in a previous _putchar call, so stop processing.*/

	if (*num_bytes == -1)
		return;

	/* Print the least significant digit in hexadecimal. */
    /* If the digit is less than 10, print it as a number (0-9).*/
    /* If the digit is 10 or more, print it as a letter (A-F).*/

	if ((numb & 15) < 10)
		wow = _putchar('0' + (numb & 15));
	else
		wow = _putchar('A' + (numb & 15) % 10);
	if (wow == -1)
		*num_bytes = -1;
	else
		*num_bytes += wow;
}

/**
 * X_print - print an integer in uppercase
 * @args: integer to print
 *
 * Return: number of bytes
 */
int X_print(va_list args)
{
	int count = 0;

	/*Extract the next argument from the list */
	/* (expected to be an integer) and print it in uppercase hexadecimal.*/

	upperHex_print(va_arg(args, int), &count);

	return (count);
}
