#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "info.h"

/**
 * init_info - initialize shell info
 * @argc: the arg count
 * @argv: the arg values
 * Return: pointer to the info
 */
info_t *init_info(int argc, char **argv)
{
	static info_t info;
	char *error = NULL;

	info.argc = argc;
	info.argv = argv;
	info.fileno = STDIN_FILENO;
	if (argc > 1)
	{
		info.file = argv[1];
		info.fileno = open(info.file, O_RDONLY);
		if (info.fileno == -1)
		{
			error = strjoin(NULL, " ", "Can't open", info.file);
			perrorl_default(*argv, info.lineno, error, NULL);
			free(error);
			info.status = 127;
			exit(free_info(&info));
		}
	}
	info.interactive = isatty(info.fileno);
	info.pid = getpid();
	info.cwd = getcwd(NULL, 0);
	info.env = env_to_dict(environ);
	return (&info);
}


/**
 * free_info - free and nullify dynamically allocated info
 * @info: pointer to the info
 * Return: current exit status
 */
int free_info(info_t *info)
{
	free(info->line);
	info->line = _getline(-1);
	free_tokens(&info->tokens);
	free(info->cwd);
	info->cwd = NULL;
	free(info->exe);
	info->exe = NULL;
	free_dict(&info->env);
	free_list(&info->path);
	free_dict(&info->aliases);
	free_cmdlist(&info->commands);
	return (info->status);
}
