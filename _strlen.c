#include "holberton.h"

/**
 *_strlen - returns the length of a string
 *@s: is a character
 * Return: 0;
 */

unsigned int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return ((1) + _strlen(s + 1));
}
