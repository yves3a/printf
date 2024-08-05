#include "main.h"

/**
 * _strdup - Creates a new copy of a given string.
 * @s: The string to copy.
 *
 * Description: This function allocates memory for a new string and copies the
 * contents of the string @s into this newly allocated space. The allocated
 * memory should be freed using free() when no longer needed.
 *
 * Return: A pointer to the new string copy, or NULL if memory allocation fails
 * or the input string is NULL.
 */
char *_strdup(const char *s)
{
	char *str_dup;
	int index = 0;

	/*Return NULL if the input string is NULL.*/
	if (s == NULL)
		return (NULL); /* handle invalid string */
	/*Allocate memory for the new string including the null terminator.*/
	str_dup = malloc(_strlen(s) + 1);

	if (str_dup == NULL)
		return (NULL);

	/*Copy each character from the original string to the new string.*/
	while (s[index] != '\0')
	{
		str_dup[index] = s[index];
		index++;
	}
	str_dup[index] = '\0';

	return (str_dup);
}
