#include "main.h"

/**
 * _memcpy - Copies a block of memory from one location to another.
 * @dest: Pointer to the destination buffer where data is to be copied.
 * @src: Pointer to the source buffer from where data is copied.
 * @n:Number of bytes to copy from source to destination.
 *
 * Description:This function copies @n bytes from the memory area pointed to
 * by @src to the memory area pointed to by @dest. It's important that the
 * source and destination memory areas do not overlap.
 *
 * Return: A pointer to @dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t j;

/*Cast the destination and source pointers*/
/*to char pointers for byte-wise copying.*/
	char *tp_dest = (char *) dest;
	const char *tp_src = (const char *) src;

/*Copy each byte from the source to the destination buffer.*/
	for (j = 0; j < n; j++)
		tp_dest[j] = tp_src[j];
	return (dest);
}
