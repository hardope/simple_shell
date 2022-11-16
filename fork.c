#include "shell.h"
/**
 * _fork - fork code to execute a new command
 * @cmd_node: Command node pointer.
 * @myself: my own name as shell.
 * @path: path received.
 * @env: env variables.
 *
 * Return: 1 on sucess, 0 on failure.
 */
int _fork(char *myself, command_t *cmd_node, char *path, char **env)
{
	pid_t status, child_pid;
	char *command;

	if (*cmd_node->command[0] == '/')
		command = cmd_node->command[0];
	else
		command = _which(path, cmd_node->command[0]);
	child_pid = fork();
	if (child_pid == -1)
	{
		error_handler(myself, 102);
		return (0);
	}
	if (child_pid == 0) /* Child process */
	{
		if (_stat(myself, command))
			_exec(command, cmd_node->command, env);
		else
			return (-1); /* Ask for custom process */
	}
	else /* Parent process */
	{
		wait(&status);
	}
	return (0);
}
