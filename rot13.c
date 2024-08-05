#include "main.h"
/**
 * rot13 - Applies ROT13 encoding to a string.
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *str)
{
	int index, j;
	char *mp1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *mp2 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	/*Iterate through each character in the string.*/
	for (index = 0; str[i] != '\0'; index++)
	{
		/*Loop through the ROT13 character map to find a match.*/
		for (j = 0; mp1[j] != '\0'; j++)
		{
			/*Loop through the ROT13 character map to find a match.*/
			if (str[index] == mp1[j])
			{
				str[index] = mp2[j];
				break;/*Exit the innerloop once the substitution is made.*/
			}
		}
	}

	return (str);/*Return the pointer to the encoded string*/
}
