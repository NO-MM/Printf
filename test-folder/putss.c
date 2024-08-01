#include "main.h"
/**
 * putss - The function that prints a string.
 *
 * @c: A string.
 *
 *Return: The number of bytes.
 */
int putss(char *c)
{
int cnt = 0;
if (c)
{
for(cnt = 0; c[cnt] != '\0'; cnt++)
{
ptchar(c[cnt]);
}
}
return (cnt);
}
