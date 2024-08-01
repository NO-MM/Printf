#include "main.h"
/**
 * ptchar - The function that prints a character.
 * @c: Character input.
 *
 * Return: 1
 */
int ptchar(char c)
{
  return (write(1, &c, 1));
}
