#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
void print_buffer(char buff[], int *b_ind);
/**
*_printf - The Printf function.
* @format: The format.
*
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
int print_chars;
conver_t funct_list[] = {
{"c", printf_char},
{"s", printf_string},
{"%", printf_percent},
{"d", printf_int},
{"i", printf_int},
{NULL, NULL}
};
va_list args;
if (format == NULL)
return (-1);
va_start(args, format);
/** parser finction*/
print_chars = parser(format,
		     funct_list, args);
va_end(args);
return (print_chars);
}
