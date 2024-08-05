#include "main.h"
#include <limits.h>
/**
 * _itob - Converts an integer to a string in the specified base.
 * @numb: the number to be converted
 * @buff: The buffer where the resulting string will be stored.
 * @base: The base for the conversion (e.g., binary, octal, decimal, hex).
 */
void _itob(ssize_t numb, char *buff, int base)
{
	size_t len = 0;
	size_t num_tp = (numb < 0) ? -numb : numb;
	ssize_t sign = numb;
	char digits;
/* Special handling for edge cases with*/
 /* the minimum value of long and short types.*/
	if (numb == LONG_MIN)
		num_tp = (size_t)LONG_MAX + 1;
	if (numb == SHRT_MIN)
		num_tp = (size_t)SHRT_MAX + 1;
	/*Ensure the base is valid (binary, octal, decimal, or hexadecimal).*/
	if (base != BIN && base != OCT && base != DEC && base != HEX)
		return;/*Exit early if the base is invalid.*/
	/*Handle the special case where the number is zero.*/
	if (num_tp == 0)
	{
		buff[len++] = '0';
	}
	else
	{
	/*Convert the number to the desired base and store each digit in the buffer.*/
		while (num_tp > 0)
		{
			digits = (char)(num_tp % base);
			buff[len++] = (digits < 10) ? digits + '0' : digits - 10 + 'a';
			num_tp /= base;
		}
	}
	/* Add a negative sign if the number is negative and in a signed base. */
	if (numb < 0 && (base == DEC || base == HEX))
	{
		sign = -numb;
		num_tp = (size_t)sign;
		buff[len++] = '-';
	}
	buff[len] = '\0';/*Null-terminate the string.*/
	str_reverse(buff, len);/*Reverse the buffer to get*/
				/*the correct order of digits.*/
}
