#include "main.h"

/**
 * handle_pointer - Converts a pointer address to a hexadecimal string and
 *                  appends it to the string buffer.
 * @spec: Pointer to the format specifier structure (unused).
 * @args: List of arguments containing the pointer to be formatted.
 * @buffer: Pointer to the string buffer where the result is stored.
 *
 * This function retrieves a pointer from the argument list, converts it to
 * a hexadecimal string, and appends it to the string buffer. If the pointer
 * is NULL, it appends "(nil)" to the buffer instead.
 *
 * Return: The number of characters added to the string buffer.
 */
int handle_pointer(__attribute__((unused)) const format_specifier *spec,
                   va_list args, string_buffer *buffer)
{
    char hex_str[17];
    int characters_printed;
    size_t initial_length = buffer->length;
    unsigned long int pointer = va_arg(args, unsigned long int);

    /* Handle NULL pointers by appending "(nil)" to the buffer */
    if (!pointer)
    {
        append_string(buffer, "(nil)");
    }
    else
    {
        /* Convert the pointer address to a hexadecimal string */
        utob(pointer, hex_str, HEX);
        append_string(buffer, "0x"); /* Prefix the hexadecimal string with "0x" */
        append_string(buffer, hex_str);
    }

    characters_printed = buffer->length - initial_length;
    return (characters_printed);
}
