#include "main.h"
#include <stdio.h>

/**
 * _atoi - Converts a string of digits into an integer.
 * @ptr: The string containing the digits to convert.
 *
 * Return: The integer value of the string.
*/


int _atoi(const char *ptr)
{
	int num = 0;

	/*Loop through each character in the string as long as it's a digit.*/
	while (isdigit(*ptr))
	{
	/*Convert the character to its numerical value and build the integer.*/
		num = num * 10 + (*ptr - '0');
		ptr++;/*Move to the next character in the string*/
	}
	return (num);
}
