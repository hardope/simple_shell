#include "shell.h"

/**
 * _exit_func - Function to exit successfully
 *
 * @environ: Environment variables.
 */

void _exit_func(char **environ)
{
	(void)environ;
	/* free_listint(*history); */
	exit(98);
}
