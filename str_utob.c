#include "main.h"
/**
 * utob - Converts a positive integer to a
 * string representation in a given base.
 * @num: The integer value to be converted.
 * @buff: The buffer where the resulting string will be stored.
 * @base: The base to which the number should be converted
 * (e.g., binary, octal, decimal, hexadecimal).
 */
void utob(size_t num, char *buff, int base)
{
	size_t len = 0;
	/*Validate the base and perform the conversion if valid.*/
	switch (base)
	{
	/*Handle the accepted bases: binary, octal, decimal, hexadecimal.*/
		case BIN:
		case OCT:
		case DEC:
		case HEX:
		/*Convert the number to the specified base and store in buffer.*/
			do {
				buff[len++] = (num % base > 9) ? ('a' + (num  % base - 10)) :
					(num % base + '0');
			} while ((num /= base) > 0);

			buff[len] = '\0';/*Null-terminate the resulting string.*/
			str_reverse(buff, len);/*Reverse the string to get corrct order*/
			break;
		default:
			break;
	}
}
