#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFERS_SIZES 1024

/* FLAGS */

#define Flag_MINUS 1 /* flag for '-' */
#define Flag_PLUS 2 /* flag for '+' */
#define Flag_ZERO 4 /* flag for '0' */
#define Flag_HASH 8 /* flag for '#' */
#define Flag_SPACE 16 /* flag for ' ' */

/* SIZES */

#define Size_LONGs 2 /* size for 'l' */
#define Size_SHORTs 1 /* size for 'h' */

/* struct to store format and corresponding function */

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/* typedef of struct fmt */
typedef struct fmt fmt_t;

/* main function to print formatted string */
int _printf(const char *format, ...);

/* helper function for printing */
int handle_print(const char *fmt, int *ni, va_list liste, char buffer[],
		int Flags, int Widths, int Precisions, int Sizes);

/* functions for printing characters and strings */
int print_char(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int print_string(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int print_percent(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);

/* functions for printing numbers */
int print_int(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int print_binary(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int print_unsigned(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int print_octal(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int print_hexadecimal(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int print_hexa_upper(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int print_hexa(va_list types, char maps_to[], char buffer[], int Flags,
		char Flag_ch, int Widths, int Precisions, int Sizes);

/* function for printing non-printable characters */
int print_non_printable(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);

/* function for printing memory address */
int print_pointer(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);

/* functions for handling format specifiers */
int get_flags(const char *format, int *ni);
int get_width(const char *format, int *ni, va_list liste);
int get_precision(const char *format, int *ni, va_list liste);
int get_size(const char *format, int *ni);

/* function to print string in reverse */
int print_reverse(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);

/* function to print a string in rot 13 */
int print_rot13string(va_list types, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);

/* functions for handling width */
int handle_write_char(char c, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int write_number(int is_Positives, int inds, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);
int write_num(int inds, char bffs[], int Flags, int Widths, int Precisions,
		int Lengths, char padds, char extrat_c);
int write_pointer(char buffer[], int inds, int Lengths, int Widths,
		int Flags, char padds, char extrat_c, int padds_start);
int write_unsgnd(int is_Negatives, int inds, char buffer[], int Flags,
		int Widths, int Precisions, int Sizes);

/******************the fonction  UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int Nums, int Sizes);
long int convert_size_unsgnd(unsigned long int Nums, int Sizes);

#endif /* MAIN_H */
