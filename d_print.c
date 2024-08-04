#include "main.h"
#include <stdio.h>

/**
 * d_print - it prints the decimal numbers
 * @args: a number to be printed 
 *
 * Return: count_num
 */
int d_print(va_list args)
{
	int num = va_arg(args, int);
	int count_num = 0, ret;
	unsigned int bcg;

	if (num < 0)
	{
		ret = _putchar('-');
		if (ret == -1)
		{
			return (-1);
		}
		count_num += 1;
		bcg = -num;
	}
	else if (num == 0)
	{
		ret = _putchar('0');
		if (ret == 1)
			return (1);
		else
			return (-1);
	}
	else 
	{
		bcg = num;
	}
	ret = numb_print(bcg);

	if (ret == 1)
	{
		count_num += countDigits(bcg);
	}
	else
		count_num = -1;
	return (count_num);
}
