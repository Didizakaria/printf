```C
#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars containing the buffer
 * @buff_ind: Pointer to the index at which to add next char, represents the length
 */
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Function that prints formatted output to stdout
 * @format: Pointer to the format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	// Declare variables
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	// Check if format string is NULL
	if (format == NULL)
		return (-1);

	// Start variadic argument list
	va_start(list, format);

	// Loop through format string
	for (i = 0; format && format[i] != '\0'; i++)
	{
		// If character is not a format specifier
		if (format[i] != '%')
		{
			// Add character to buffer
			buffer[buff_ind++] = format[i];
			// If buffer is full, print contents and reset index
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			// Increment number of printed characters
			printed_chars++;
		}
		else
		{
			// If character is a format specifier, print contents of buffer and get format information
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			// Handle the format specifier and get the number of characters printed
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			// If there is an error, return -1
			if (printed == -1)
				return (-1);
			// Increment number of printed characters
			printed_chars += printed;
		}
	}

	// Print the remaining contents of the buffer
	print_buffer(buffer, &buff_ind);

	// End variadic argument list
	va_end(list);

	// Return number of characters printed
	return (printed_chars);
}
