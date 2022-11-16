#include "shell.h"
/**
 * verif_built_comm - Execute the builtins commands.
 * @str: First arg.
 * @env: Environment variables.
 *
 * Return: 0 or -1 in failure.
 */

int verif_built_comm(char *str, char **env)
{
	int iterator, result;
	built_t built_func[] = {
		{"env", print_env},
		{"exit", _exit_func},
		{NULL, NULL}
	};
	for (iterator = 0; built_func[iterator].command != NULL; iterator++)
	{
		result = _strcmp(str, built_func[iterator].command);
		if (result == 0)
		{
			built_func[iterator].f(env);
			return (1);
		}
	}
	return (0);
}
