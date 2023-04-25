#include "main.h"

void write_buffer(char buffer[], int *buff_ind);

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, printed_chars = 0, buffer_index = 0;
	int flags, widths, precisions, sizes;

	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];

			if (buffer_index == BUFFER_SIZE)
				write_buffer(buffer, &buffer_index);

			printed_chars++;
		}
		else
		{
			write_buffer(buffer, &buffer_index);

			flags = get_flags(format, &i);
			widths = get_width(format, &i, args);
			precisions = get_precision(format, &i, args);
			sizes = get_size(format, &i);
			i++;

			printed_chars += handle_print(format, &i, args, buffer,
							flags, widths, precisions, sizes);
		}
	}

	write_buffer(buffer, &buffer_index);
	va_end(args);

	return (printed_chars);
}

/**
 * write_buffer - write to buffer
 * @buffer: array of characters
 * @buffer_index: Index at which to add the next character
 */

void write_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, &buffer[0], *buffer_index);
	}
	*buffer_index = 0;
}
