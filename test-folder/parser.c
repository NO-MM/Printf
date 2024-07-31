#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * parser - Parses a format string and handles custom formatting.
 * @format: The format string containing text and format specifiers.
 * @funct_list: An array of structures with symbols and corresponding
 * function pointers.
 * @args: A va_list of arguments to be formatted.
 *
 * Description: This function iterates through the format string, looking for
 *              format specifiers (indicated by '%'). When a format specifier
 *              found, it checks the funct_list array for a matching symbol and
 *              calls the corresponding function. The function handles printing
 *              characters directly if they are not part of a format specifier.
 *
 * Return: The total number of characters printed. If an error occurs (e.g., an
 *         invalid format specifier or an unexpected end of the format string),
 *         the function returns -1.
 */
int parser(const char *format, conver_t funct_list[], va_list args)
{
int i, a;
int print_chars = 0;
int found;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
found = 0;
for (a = 0; funct_list[a] != NULL; a++)
{
if (format[i] == 's')
{
int r_val = funct_list[a](args);
if (r_val == -1)
{
return (-1);
}
print_chars += r_val;
found = 1;
break;
}
}
if (!found)
{
if (format[i] != '\0')
{
_putchar('%');
_putchar(format[i]);
print_chars += 2;
}
else
{
return (-1);
}
}
}
else
{
_putchar(format[i]);
print_chars++;
}
}
return (print_chars);
}
