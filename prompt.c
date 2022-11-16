#include "shell.h"
/**
 * _prompt - write prompt and read a command line.
 * @myself: String for prompt init.
 * @argv: shell arguments.
 * @hist: History head list.
 *
 * Return: NULL or pointer to command list.
 */
command_t **_prompt(char *myself, char *argv)
{
	size_t buff_size = 0;
	ssize_t char_amount = 0;
	char *cmd_line = NULL;
	command_t *cmd_node = NULL;
	command_t **cmd_list = &cmd_node; /* Command List */

	if (isatty(STDIN_FILENO))
	{
		/* write(STDOUT_FILENO, shell_phrase, char_amount); */
		/* ToDO: Insert new _getline */
		char_amount = getline(&cmd_line, &buff_size, stdin);
	}
	else
	{
		/* Take command from **argv */
		cmd_line = argv;
	}
	fflush(stdin);
	/* Insert into history here */

	/* print_listint(*hist); */
	if (char_amount < 0)
		cmd_list = NULL;
	else
	{
		*cmd_list = _parser_cmd(myself, cmd_line);
		free(cmd_line);
		cmd_line = NULL;
		return (cmd_list);
	}
	return (NULL);
}
