#include "string.h"

/**
  * _strnchr - get the index of the first matching character
  * @str: string passed
  * @chr: character passed
  * @n: max number of characters to check
  * Return: Index of the first occurence, or -1 chr is not found
  */
ssize_t _strnchr(const char *str, char chr, size_t n)
{
	ssize_t index;

	if (!str)
		return (-1);

	for (index = 0; n && str[index]; --n, ++index)
	{
		if (str[index] == chr)
			return (index);
	}

	return (-1);
}


/**
 * _strndup - duplicate the given string
 * @str: the string to duplicate
 * @n: the max number of bytes to copy
 *
 * Description: This function copies at most n bytes. If str is longer
 * than n, only n bytes are copied, and a terminating null byte is added.
 *
 * Return: If str is NULL or if memory allocation fails, return NULL.
 * Otherwise a return a pointer to the dynamically-allocated duplicate.
 */
char *_strndup(const char *str, size_t n)
{
	char *dup;
	size_t len = 0;

	if (!str)
		return (NULL);

	while (n && str[len])
		--n, ++len;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	dup[len] = '\0';

	while (len--)
		dup[len] = str[len];

	return (dup);
}


/**
 * _strnlen - calculate the length of a string
 * @str: the string to measure
 * @n: the max number of characters to check
 * Return: the lesser of n and the length of the string
 */
ssize_t _strnlen(const char *str, size_t n)
{
	const char *pos = str;

	if (!str)
		return (-1);

	while (n && *pos)
		--n, ++pos;

	return (pos - str);
}



/**
 * _strncmp - compare two strings
 * @s1: a string to compare
 * @s2: the other string to compare
 * @n: the max number of bytes to compare
 * Return: 0 if s1 matches s2,
 * otherwise an integer less than 0 if s1 is less than s2,
 * otherwise an integer greater than 0 if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for (; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}

	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}

	return (0);
}


/**
 * _strncpy - copy the string
 * @dest: destination
 * @src: source
 * @n: the max number of bytes to copy
 *
 * Description: This function copies at most n bytes from src to dest. A
 * null byte will NOT be written if not found in the first n bytes
 *
 * Return: a pointer to dest
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	char *pos = dest;

	for ( ; n && *src; --n)
		*pos++ = *src++;
	if (n)
		*pos = '\0';

	return (dest);
}
