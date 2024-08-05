#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @str: Pointer to the input string.
 *
 * This function calculates the number of characters in the string
 * pointed to by `str`, excluding the null terminator character '\0'.
 *
 * Return: The length of the string
 * (number of characters before the null terminator).
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	/*
	 * Iterate through the string until the null terminator is encountered
	 */
	while (*str++)
	{
		len++;
		/*
		 * Increment the length counter for each character
		 */
	}

	return (len);
	/*
	 * Return the calculated length
	 */
}
