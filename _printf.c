#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - function that produces output according to a format
 * @format: pointer to character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0;
	va_list args;
	print_func_t funcs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; funcs[j].spec; j++)
			{
				if (format[i + 1] == funcs[j].spec)
				{
					count += funcs[j].f(args);
					break;
				}
			}
			if (!funcs[j].spec)
			{
				_putchar(format[i]);
				count++;
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(args);
	return (count);
}

/**
 * print_char - function that prints a character
 * @args: arguments list
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * print_string - function that prints a string
 * @args: arguments list
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i;

	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}

/**
 * print_percent - function that prints a percent symbol
 * @args: arguments list
 *
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
