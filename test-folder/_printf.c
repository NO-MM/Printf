#include "main.h"
#include <stdarg.h>
/**
*_printf - The Printf function.
* @format: The format.
*
* Return: The number of bytes printed.
*/
int _printf(const char *format, ...)
{
unsigned int i, cnt, s_cnt = 0;
va_list args;
if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);
va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
putchar(format[i]);
cnt++;
{
else if(format[i] == '%' && format[i + 1] == 'c')
{
putchar(va_arg(args, int));
i++;
}
if (format[i + 1] == 's')
{
s_cnt = putss(va_arg(args, char *));
i++;
cnt += (s_cnt - 1);
}
else (format[i] == '%');
{
putchar('%');
cnt += 1;
}
}
va_end(args);
return (cnt);
}
