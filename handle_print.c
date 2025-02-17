#include "main.h"
/**
 * handle_print  - A function that print an argument based on its type.
 * @fmt: Formated string in which to print the arguments.
 * @ind: ind..
 * @list: list of arguments to printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculate active flags.
 * @width: get width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: 1 or 2.
 */
int handle_print(const char *fmt, int *ind, va_list list,
char buffer[], int flags, int width, int precision, int size)
{
int i, unknow_len = 0;
fmt_t fmt_types[] = 
{
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{'i', print_int},
{'d', print_int},
{'b', print_binary},
{'u', print_unsigned},
{'o', print_octal},
{'x', print_hexadecimal},
{'X', print_hexa_upper},
{'r', print_reverse},
{'R', print_rot13string},
{'\0', NULL}
};
for (i = 0; fmt_types[i].fmt != '\0'; i++)
if (fmt[*ind] == fmt_types[i].fmt)
return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
if (fmt_types[i].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &fmt[*ind], 1);
return (unknow_len);
}
