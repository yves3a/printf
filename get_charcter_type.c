#include "main.h"

/**
 * get_char - based on the specifier it determines and select
 * which printf function that can be used.
 * @specifier: a char that looks for the type of variable to print
 *
 * Return: a pointer to a matching function
 */

int (*get_char(const char *specifier))(va_list)
{
	int a;
	type_t types[] = {
		{"c", c_print},
		{"s", s_print},
		{"d", d_print},
		{"i", d_print},
		{NULL, NULL}
	};

	for (a = 0; types[a].identifier; a++)
	{
		if (*specifier == types[a].identifier[0])
		{
			return (types[a].print);
		}
	}
	return (NULL);
}
