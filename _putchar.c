#include "main.h"

/**
 * _putchar - function to print char
 * @c: char
 * Return: 1 if success or -1 if fail
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
