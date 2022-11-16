#include "dict.h"

/**
  * get_dict_val - get a value from a dictionary
  * @head: dict
  * @key: entry key
  *
  * Return: pointer to the entry value
  */
char *get_dict_val(dict_t *head, const char *key)
{
	if (!key)
		return (NULL);

	while (head)
	{
		if (!_strcmp(head->key, key))
			return (head->val);
		head = head->next;
	}

	return (NULL);
}


/**
  * get_dict_node - retrieve a node by key
  * @head: dict
  * @key: entry key
  *
  * Return: node or NULL
  */
dict_t *get_dict_node(dict_t *head, const char *key)
{
	if (!head)
		return (NULL);
	if (!_strcmp(head->key, key))
		return (head);
	return (get_dict_node(head->next, key));
}


/**
  * add_dict_node_end - adds node at the end of list
  * @headptr: pointer to dict
  * @key: entry key
  * @val: entry val
  * Return: pointer to list
  */
dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val)
{
	dict_t *new;

	if (!headptr)
		return (NULL);

	if (*headptr)
		return (add_dict_node_end(&((*headptr)->next), key, val));

	new = malloc(sizeof(dict_t));
	if (!new)
		return (NULL);

	new->key = _strdup(key);
	new->val = _strdup(val);
	new->next = NULL;

	*headptr = new;
	return (new);
}


/**
  * del_dict_node - delete a node
  * @headptr: pointer to dict
  * @key: entry key
  *
  * Return: pointer to resulting list
  */
dict_t *del_dict_node(dict_t **headptr, const char *key)
{
	dict_t *tmp;

	if  (!(headptr && *headptr))
		return (NULL);
	if (!_strcmp((*headptr)->key, key))
	{
		tmp = *headptr;
		(*headptr) = tmp->next;
		free(tmp->key);
		free(tmp->val);
		free(tmp);
	}
	else
		del_dict_node(&((*headptr)->next), key);
	return (*headptr);
}


/**
 * free_dict - free a linked list and and set head to NULL
 * @headptr: the first list node
 */
void free_dict(dict_t **headptr)
{
	if (!*headptr)
		return;

	free_dict(&((*headptr)->next));
	free((*headptr)->key);
	free((*headptr)->val);
	free(*headptr);
	*headptr = NULL;
}
