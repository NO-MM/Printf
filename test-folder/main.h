#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/**
 * struct convert - A structure to map format specifiers to
 * thier corresponding functions.
 * @sym: The format specifier symbol (e.g., "c" for char, "s" for string).
 * @f: A pointer to the function that handles the format specifier.
 *
 * Description: This structere is used to associate format specifiers
 * with their corresponding functions. Each entry in the structure contains
 * a symbol representing the format specifier and a function pointer to the
 * function that will handle the printing of the corresponing
 * argument type.
 */
struct convert
{
char *sym;
int (*f)(va_list);
};
typedef struct convert conver_t;
/*These are functions to print chars and strings */
int _putchar(char c);
int _printf(const char *format, ...);
void _vaprintf(const char *format, va_list args);
int parser(const char *format, conver_t funct_list[],
	   va_list args);
int printf_char(va_list);
int printf_string(va_list arg);
int printf_percent(va_list);
int printf_int(va_list);
int printf_num(va_list);
int printf_unsigned_num(unsigned int n);
#endif
