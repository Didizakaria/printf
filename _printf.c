#include "main.h"

/**
 * check_sp - check which specifier to print
 * @format: string passed
 * @print_arr: array of struct
 * @list: arguments
 * Return: numb of char to be printed
 */
int check_sp(const char *format, fmt_t *print_arr, va_list list)
{
	int count = 0, i = 0, j = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			i++;
			while (print_arr[j].type != NULL &&
			       format[i] != *(print_arr[j].type))
				j++;
			if (print_arr[j].type != NULL)
				count = count + print_arr[j].f(list);
			else
			{
				if (format[i] == '\0')
					return (-1);
				if (format[i] != '%')
					count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	return (count);
}

/**
 * _printf - prints according to format
 * @format: string passed
 * Return: char to be printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int a = 0;

	fmt_t ops[] = {
		{"c", ch},
		{"s", str},
		{"d", _int},
		{"b", _bin},
		{"i", _int},
		{"u", _ui},
		{"o", _oct},
		{"x", _hex_l},
		{"X", _hex_u},
		{"R", _rot13},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(list, format);
	a = check_sp(format, ops, list);
	va_end(list);
	return (a);
}
