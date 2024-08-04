#include "main.h"
#include <stdio.h>

/**
 * b_print - Prints the binary representation of an unsigned integer.
 * @args: The va_list containing the integer to print.
 *
 * Return: number of characters printed
 */

int b_print(va_list args)
{
	int count_num = 0, ret, i = 1;
	unsigned int dec_Number = va_arg(args, unsigned int);
	char *str;

	if (dec_Number < 1)
	{
		_putchar(0 + '0');
		return (1);
	}
	/*Count the number of binary digits required.*/

	count_num += countBinary(dec_Number);
	/*Allocate memory to store the binary digits as characters.*/
	str = malloc(sizeof(char) * (count_num + 1));

	/*If memory allocation fails, return -1 to indicate an error.*/
	if (str == NULL)
		return (-1);

	/*Convert the decimal number to binary by continuously dividing by 2.*/
	for (i = 1; i < count_num + 1; i++)
	{
		str[count_num - i] = dec_Number % 2;
		dec_Number = dec_Number / 2;
	}
	/*Print the binary digits stored in the string.*/
	for (i = 0; i < count_num; i++)
	{
		ret = _putchar(str[i] + '0'); /*Convert the binary digit*/
						/* to a character and print it.*/

		if (ret == -1)/*If _putchar fails, free the allocatedmemory and return -1.*/
		{
			free(str);
			return (-1);
		}
	}
/*ree the allocated memory and return the number of characters printed.*/
	free(str);
	return (count_num);
}
