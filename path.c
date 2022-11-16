#include "holberton.h"

/**
 * find_path - function that finds the path
 * @environ: global variable environment
 * Return: path in tokens
 */

char **find_path(char **environ)
{
	char *get_path, **tokens, *delim;

	delim = ":";
	get_path = _getenv(environ, "PATH");
	tokens = splits(get_path, delim);
	return (tokens);
}
