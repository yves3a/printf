#include "main.h"

/**
 * numb_print - we are printing numbers
 * @n: a number to print
 *
 * Return: on success. returns the last _putchar result(typically 1).
 * on error, returns -1.
 */

int numb_print(unsigned int n)
{
	int ret;
	unsigned int numb = n;

	/*Recursively print higher digits.*/

	if (numb / 10)
		numb_print(numb / 10);
	/*Print the current digit (least significant digit).*/
	ret = _putchar('0' + numb % 10);

	/*Check for _putchar error and return the result.*/
	if (ret == -1)
	{
		return (ret);
	}

	return (ret);
}

/**
 * countDigits - it counts the number of digits in unsigned
 *		integer numb.
 * @numb: a number to count digits in.
 *
 * Return: number of digits.
 */
int countDigits(unsigned int numb)
{
	int count_dig = 0;

	/*Loop until the number is reduced to zero.*/
	while (numb > 0)
	{
		count_dig++; /*Increment digit count.*/
		numb /= 10; /*Remove the last digit.*/
	}
	return (count_dig);
}


/**
 * countBinary - it counts the number of digits passed
 * @numb: the number to be counted.
 *
 * Return: count
 */
int countBinary(unsigned int numb)
{
	int count_dig = 0;
	/*iterating through the digits of the number*/
	while (numb > 0)
	{
		count_dig++;
		numb /= 10;
	}
	return (count_dig); /*returns the number of digits of a number*/
}
