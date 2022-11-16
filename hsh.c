#include "hsh.h"

/**
 * main - entry point
 * @argc: the argument count
 * @argv: the argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	info_t *info = init_info(argc, argv);

	signal(2, _sigint);

	while (read_input(info))
	{
		parse(info);
		while ((info->tokens = pop_cmd(&(info->commands))))
		{
			execute(info);
			free_tokens(&(info->tokens));
		}
		free(info->line);
		info->line = NULL;
	}
	if (info->interactive)
		write(STDOUT_FILENO, "\n", 1);

	if (info->file)
		close(info->fileno);

	exit(free_info(info));
}
