#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produces output according to a format
 * @format: Character string containing zero or more directives
 * Return: Number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%') // Found a conversion specifier
		{
			format++; // Move past the %
			switch (*format)
			{
				case 'c': // Print a single character
					count += _putchar(va_arg(args, int));
					break;
				case 's': // Print a string
					count += _putstr(va_arg(args, char *));
					break;
				case '%': // Print a %
					count += _putchar('%');
					break;
				default: // Unknown conversion specifier
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else // Regular character, just print it
		{
			count += _putchar(*format);
		}

		format++; // Move to next character
	}

	va_end(args);

	return (count);
}
