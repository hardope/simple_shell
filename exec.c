#include "shell.h"
/**
 * _exec - execve implementation for Simple Shell.
 * @command: Command to execute.
 * @cmd: Command to execute.
 * @env: Command to execute.
 *
 * Return: Always 0.
 */
int _exec(char *command, char **cmd, char **env)
{

	/* (void)cmd; */
	if (execve(command, cmd, env) == -1)
	{
		perror("Error:");
	}
	return (0);
}
