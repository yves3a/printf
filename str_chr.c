#include "main.h"
/**
 * str_chr - Finds the first occurrence of a character in a string.
 * @str: The string to search within.
 * @c: The character to find in the string.
 *
 * Description: This function searches for the first instance of the character
 * @c in the provided string @str. If the character is found, a pointer to its
 * location in the string is returned.
 *
 * Return: A pointer to the first occurrence of @c in @str, or NULL if @c is
 * not found.
 */
char *str_chr(const char *str, int c)
{
	/*Cast the input string to a modifiable pointer.*/
	char *tp_str = (char *) str;

	/*Return NULL if the input string is NULL.*/
	if (tp_str == NULL)
		return (NULL);

	while (*tp_str != '\0')
	{
		if (*tp_str == c)
			return (tp_str); /*Return pointer to the character if found.*/
		tp_str++;
	}
/*If searching for the null terminator,return a */
	/*pointer to the end of the string */
	if (c == '\0')
		return (tp_str);

	return (NULL); /*Return NULL if the character is not found.*/
}
