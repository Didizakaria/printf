#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = parse_format(format, args);
	va_end(args);

	return (count);
}

/**
 * parse_format - parses the format string and prints arguments
 * @format: format string
 * @args: argument list
 *
 * Return: number of characters printed
 */
int parse_format(const char *format, va_list args)
{
	int count = 0;
	const char *ptr = format;

	while (*ptr != '\0')
	{
		if (*ptr != '%')
		{
			_putchar(*ptr);
			count++;
		}
		else
		{
			ptr++;
			if (*ptr == '\0')
				return (-1);
			count += print_arg(*ptr, args);
		}
		ptr++;
	}

	return (count);
}

/**
 * print_arg - prints an argument based on the format specifier
 * @spec: format specifier
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_arg(char spec, va_list args)
{
	switch (spec)
	{
	case 'c':
		return (_putchar(va_arg(args, int)));
	case 's':
		return (_puts(va_arg(args, char *)));
	default:
		return (_putchar('%') + _putchar(spec));
	}
}

/**
 * _putchar - writes a character to stdout
 * @c: character to write
 *
 * Return: on success, 1. On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes a string to stdout
 * @str: string to write
 *
 * Return: number of characters written
 */
int _puts(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		str = "(null)";
		len = 6;
	}

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		len++;
	}

	return (len);
}
