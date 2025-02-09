#include "main.h"
/********** WRITE HANDLE **********/
/**
 * handle_write_char - The printed string.
 * @c: char types.
 * @buffer: Buffer array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: precicion specifier.
 * @size: Size specifier.
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[], int flags,
int width, int precision, int size)
{
int i = 0;
char padd = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
padd = '0';
buffer[i++] = c;
buffer[i] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (i = 0; i < width - 1; i++)
buffer[BUFF_SIZE - i - 2] = padd;
if (flags & F_MINUS)
{
return (write(1, &buffer[0], 1) + write(1,
&buffer[BUFF_SIZE - i - 1], width - 1));
}
else
{
return (write(1,&buffer[BUFF_SIZE - i - 1],
width - 1) + write(1, &buffer[0], 1));
}
}
return (write(1, &buffer[0], 1));
}
/********** WRITE NUMBER **********/
/**
 * write_number - The function that print a string.
 * @is_negative: List of arguments.
 * @ind: char types.
 * @buffer: Buffer array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: precicion specifier.
 * @size: Size specifier.
 * @padd: The padding char.
 * @length: Number length. 
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';
return (write_num(ind, buffer, flags, width,
precision, length, padd, extra_ch));
}
/**
 * write_num - The function that print a string.
 * @ind: char types.
 * @buffer: Buffer array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @prec: precicion specifier.
 * @extra_c: Char representing extra char
 * @padd: The padding char
 * @length: umber length. 
 *
 * Return: Number of chars printed.
 */
int write_num(int ind, char buffer[],
int flags, int width, int prec, int length,
char padd, char extra_c)
{
int i, padd_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind]
== '0' && width == 0)
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind]
== '0')
buffer[ind] = padd = ' ';
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (i = 1; i < width - length + 1; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--padd_start] = extra_c;
return (write(1, &buffer[padd_start], i - padd_start) + write(1,
&buffer[ind], length - (1 - padd_start)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}
/**
 * write_unsgnd - The function that write unsigned number.
 * @is_negetive: Lista of arguments.
 * @ind: char types.
 * @buffer: Buffer array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: precicion specifier.
 * @size: Size specifier.
 * @length: umber length.
 *
 * Return: Number of chars printed.
 */
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1, i = 0; char padd = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision > 0 && precision < length) padd = ' ';
while (precision > length)
{
buffer[--ind] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS)) padd = '0';
if(width > length)
{
for (i = 0; i < width - length; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS)
{
return (write(1, &buffer[ind], length) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}
/**
 * write_pointer - The function that write memory address.
 * @ind: The  index number that start the buffer.
 * @buffer: Buffer array of char.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @extra_c: Char representing extra char.
 * @padd: The padding char.
 * @padd_start: Where padding should start.
 *
 * Return: Number of chars written.
 */
int write_pointer(char buffer[], int ind,
int length, int width, int flags, char padd,
char extra_c, int padd_start)
{
int i;
if (width > length)
{
for (i = 3; i < width - length + 3; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
