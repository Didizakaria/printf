#include "main.h"

/**
 * is_printable - Determines whether a character is printable or not.
 * @c: The character to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise.
 */
int is_printable(char c)
{
	/* Printable characters are in the range of 32 to 126 in ASCII */
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Appends the ASCII code in hexadecimal format to the buffer.
 * @buffer: The buffer to which the hexadecimal code is to be appended.
 * @i: The index at which to start appending.
 * @ascii_code: The ASCII code to be converted to hexadecimal.
 * Return: Always 3.
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	/* The hexadecimal format code is always 2 digits long */
	char map_to[] = "0123456789ABCDEF";

	/* If ascii_code is negative, make it positive */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Determines whether a character is a digit or not.
 * @c: The character to be evaluated.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size.
 * @num: The number to be casted.
 * @size: The size to which the number is to be casted.
 *
 * Return: Casted value of num.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts an unsigned number to the specified size.
 * @num: The number to be casted.
 * @size: The size to which the number is to be casted.
 *
 * Return: Casted value of num.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
