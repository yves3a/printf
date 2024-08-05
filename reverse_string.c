#include "main.h"

/**
 * str_reverse - reverse string in place
 *
 * @buffer: string to be reversed
 * @len: length of the string to be reversed
 */
void str_reverse(char *buffer, size_t len)
{
	size_t ind, mid;
	char j;

	/*If the buffer is NULL, there's nothing to reverse.*/
	if (!buffer)
		return;
	/*Calculate the midpoint of the string.*/
	mid = len / 2;
	/*Swap characters from the ends toward the center.*/
	for (ind = 0; ind < mid; i++)
	{
	/*Temporarily hold the current character.*/
		j = buffer[i];

		/* Swap the character with its corresponding pair from the end.*/
		buffer[ind] = buffer[len - ind - 1];
		buffer[len - ind - 1] = c;
	}
}
