#include "env.h"

/**
  * env_to_dict - creates a list from environment
  * @env: environment passed
  * Return: head
  */
env_t *env_to_dict(char **env)
{
	env_t *head = NULL;

	if (!_env_to_dict(&head, env))
		free_dict(&head);

	return (head);
}


/**
 * _env_to_dict - turn the environment into a linked list (helper)
 * @tailptr: pointer to the tail of the list
 * @env: environment
 *
 * Return: pointer to the tail of the list
 */
env_t *_env_to_dict(env_t **tailptr, char **env)
{
	env_t *tail;
	char *env_str;
	ssize_t key_len;

	if (!*env)
		return (*tailptr);

	env_str = _strdup(*env);
	if (!env_str)
		return (NULL);

	key_len = _strchr(*env, '=');

	if (key_len == -1)
		return (NULL);

	env_str[key_len] = '\0';
	tail = add_dict_node_end(tailptr, env_str, env_str + key_len + 1);
	free(env_str);

	return (_env_to_dict(&tail, env + 1));
}
