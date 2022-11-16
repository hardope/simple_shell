#include "hsh.h"

/**
 * expand_aliases - perform recursive alias expansion on the current command
 * @aliases: alias list
 * @tokptr: pointer to the current tokens
 *
 * Return: If expansion succeeds, return a pointer t to the otherwise 0
 */
void expand_aliases(alias_t *aliases, char ***tokptr)
{
	char **new, **old, *name, *value, *temp;

	if (!*tokptr)
		return;
	do {
		name = expand_alias(aliases, tokptr);
		value = get_dict_val(aliases, name);
		if (value && *value && _isspace(value[_strlen(value) - 1]))
		{
			old = *tokptr;
			new = arrdup(old + 1);

			expand_aliases(aliases, &new);
			temp = *(old + 1);

			*(old + 1) = NULL;
			*tokptr = arrjoin(old, new);
			*(old + 1) = temp;

			free_tokens(&old);
			free_tokens(&new);
		}
	} while (name && **tokptr && _strcmp(name, **tokptr));
}


/**
 * expand_alias - perform a single alias expansion on the current command
 * @aliases: alias list
 * @tokptr: pointer to the current tokens
 *
 * Return: If expansion succeeds, return a pointer the alias name.
 * Otherwise, return NULL.
 */
char *expand_alias(alias_t *aliases, char ***tokptr)
{
	char **alias_tokens, **tokens = *tokptr;

	if (!*tokens)
		return (NULL);

	while (aliases)
	{
		if (!_strcmp(*tokens, aliases->key))
		{
			alias_tokens = tokenize(aliases->val);
			*tokptr = arrjoin(alias_tokens, tokens + 1);

			free_tokens(&tokens);
			free_tokens(&alias_tokens);

			return (aliases->key);
		}
		aliases = aliases->next;
	}
	return (NULL);
}
