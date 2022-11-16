#include "holberton.h"

/**
 *_puts - prints a string
 *@str: is a character
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
