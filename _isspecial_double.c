#include "quote.h"

/**
 * _isspecial_double - check if a character is special inside double quotes
 * @c: the character to check
 * Return: If c is special, return 1. Otherwise, return 0.
 */
int _isspecial_double(char c)
{
	return (c == '"' || c == '$' || c == '\\');
}
