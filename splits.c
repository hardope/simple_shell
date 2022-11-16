#include "holberton.h"

/**
 * _realloc - reallocate memory
 * @ptr: void variable pointer
 * @old_size: integer
 * @new_size: integer
 * Return: Null
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	char *new;
	unsigned int i;

	if (ptr == NULL)
	{
		new = malloc(new_size);
		return (new);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new = malloc(new_size);

	if (new == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
	{
		new[i] = ((char *)ptr)[i];
	}

	free(ptr);

	return (new);
}

/**
 * splits - function that create tokens
 * @line: is a char
 * @delim: is a char
 * Return: double pointer
 */

char **splits(char *line, char *delim)
{
	char **pptoken;
	int buf = 1024, i = 0;

	pptoken = malloc(sizeof(char *) * buf);
	if (!pptoken)
		exit(99);

	pptoken[i] = strtok(line, delim);
	i++;
	while (1)
	{
		pptoken[i] = strtok(NULL, delim);
		if (i >= buf)
		{
			buf += buf;
			pptoken = _realloc(pptoken, buf, buf * (sizeof(char *)));
			if (!pptoken)
				exit(98);
		}
		if (pptoken[i] == NULL)
			break;
		i++;
	}
	return (pptoken);
}
