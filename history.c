#include "shell.h"

/**
 * *add_nodeint - Add node in the begin67ning
 * @head: The pointer of the history list.
 * @str: The string received.
 *
 * Return: On success 1
 */

int add_nodeint(history_t **head, char *str)
{
	history_t *new = malloc(sizeof(head));
	history_t *copy = *head;

	if (!new)
	{
		free_listint(*head);
		return (-1);
	}

	new->comms = _strdup(str);
	/* printf("DEBUG: Address comms %p\n", (void*)&new->comms);  */
	/*  printf("DEBUG: Address new %p\n", (void*)&new);  */
	/*  printf("DEBUG: Address new next  %p\n", (void*)&new->next);  */
	/*  printf("DEBUG: Address new prev %p\n", (void*)&new->prev);  */
	if (new->comms == NULL)
	{
		free_listint(*head);
		return (-1);
	}
	new->prev = NULL;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		new->next = copy;
		*head = new;
	}
	return (1);
}

/**
 * free_listint - Print the list of a single list
 * @head: The pointer of the list
 *
 * Return: The number of elements in the list
 */

void free_listint(history_t *head)
{
	history_t *delete;

	if (!head)
		return;
	while (head)
	{
		delete = head->next;
		free(head->comms);
		free(head->prev);
		free(head);
		head = delete;
	}
	free(delete);
}

/**
 * print_listint - Print the list of a single list
 * @h: The pointer of the list.
 *
 * Return: The number of elements in the list
 */

void print_listint(const history_t *h)
{
	while (h)
	{
		printf(":DEBUGG history :%s\n", h->comms);
		h = h->next;
	}
}
