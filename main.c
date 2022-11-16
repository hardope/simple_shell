#include "holberton.h"

/**
 * main - principal function
 * @argc: is an int
 * @argv: is a char
 * @environ: global variable
 * Return: 0
 */

int main(int argc, char **argv, char **environ)
{
	char *line = NULL;
	char *delim = "\t \a\n";
	char *command;
	char **tokens;
	(void)argc;

	tokens = find_path(environ);

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		line = read_line();
		argv = splits(line, delim);
		command = args_path(argv, tokens);
		if (command == NULL)
			execute(argv);
		free(line);
		free(argv);
		free(command);
	}
	return (0);
}
