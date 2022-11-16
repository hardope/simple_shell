#include "ctype.h"

/**
  * _isalnum - checks if the character is alphanumeric
  * @c: character to check
 * Return: If c is alphanumeric, return 1. Otherwise, return 0.
  */
bool _isalnum(int c)
{
	return (_isalpha(c) || _isdigit(c));
}
