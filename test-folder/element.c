#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * printf_num - Prints an integer number.
 * @args: The list of arguments.
 *
 * This function takes a variable argument
 * list, extracts an integer, and prints it.
 * It handles negative numbers by printing
 * a '-' sign and then the absolute value
 * of the number.
 *
 * Return: The number of characters printed.
 */
int printf_num(va_list args)
{
int n;
int ch = 1;
int len = 0;
unsigned int num;
n = va_arg(args, int);
ch = 1;
len = 0;
if (n < 0)
{
len += _putchar('-');
num = -n;
}
else
{
num = n;
}
if (num == 0)
{
len += _putchar('0');
return (len);
}
while (num / ch >= 10)
{
ch *= 10;
}
while (ch > 0)
{
len += _putchar('0' + num / ch);
num %= ch;
ch /= 10;
}
return (len);
}
/**
 * print_unsigned_number - Prints an unsigned
 * integer number.
 * @n: The unsigned integer to be printed.
 *
 * This function prints an unsigned integer
 * by breaking it down into
 * individual digits and printing each digit.
 *
 * Return: The number of characters printed.
 */
int print_unsigned_num(unsigned int n)
{
int ch = 1;
int len = 0;
unsigned int num = n;
if (num == 0)
{
len += _putchar('0');
return (len);
}
while (num / ch >= 10)
{
ch *= 10;
}
while (ch > 0)
{
len += _putchar('0' + num / ch);
num %= ch;
ch /= 10;
}
return (len);
}
/**
 * printf_char - Prints a character.
 * @args: The list of arguments.
 *
 * This function takes a variable argument
 * list, extracts a character, and prints it.
 *
 * Return: Always returns 1 (the number
 * of characters printed).
 */
int printf_char(va_list args)
{
char c = va_arg(args, int);
putchar(c);
return (1);
}
/**
 * printf_string - Prints a string.
 * @args: The list of arguments.
 *
 * This function takes a variable argument
 * list, extracts a string,
 * and prints it character by character.
 *
 * Return: The number of characters printed.
 */
int printf_string(va_list args)
{
int i;
const char *s;
s = va_arg(args, const char *);
if(s == NULL)
{
s = "(null)";
}
for (i = 0; s[i] != '\0'; i++)
{
_putchar(s[i]);
}
return (i);
}
/**
 * printf_percentage - Prints a percentage sign.
 * @args: The list of arguments.
 *
 * This function prints a percentage sign. It
 * does not use the argument list.
 *
 * Return: Always returns 1 (the number of
 * characters printed).
 */
int printf_percent(__attribute__((unused))
		   va_list args)
{
_putchar('%');
return (1);
}
/**
 * printf_num - Prints an integer number.
 * @args: The list of arguments.
 *
 * This function takes a variable argument list,
 * extracts an integer, and prints it. It handles
 * negative numbers by printing a '-' sign
 * and then the absolute value of the number.
 *
 * Return: The number of characters printed.
 */
int printf_int(va_list args)
{
int n = va_arg(args, int);
return printf("%d", n);
}
