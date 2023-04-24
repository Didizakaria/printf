#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int parse_format(const char *format, va_list args);
int print_arg(char spec, va_list args);
int _putchar(char c);
int _puts(char *str);

#endif /* MAIN_H */
