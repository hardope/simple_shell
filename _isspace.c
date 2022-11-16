#include "ctype.h"

/**
 * _isspace - check if a character is whitespace
 * @c: the character to check
 * Return: If c is whitespace, return 1. Otherwise, return 0.
 */
bool _isspace(int c)
{
	return (c == ' ' || (c >= 0x09 && c <= 0x0d));
}
