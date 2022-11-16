#include "hsh.h"

/**
  * execute - execute a command
  * @info: arguments passed
  *
  * Return: status
  */
int execute(info_t *info)
{
	const builtin_t *builtin = get_builtin(*info->tokens);

	if (builtin)
	{
		return (builtin->f(info));
	}
	if (_strchr(*info->tokens, '/') == -1)
	{
		free_list(&info->path);
		info->path = str_to_list(get_dict_val(info->env, "PATH"), ':');
		info->exe = search_path(info, info->path);
	}
	else
	{
		info->exe = _strdup(*info->tokens);
	}
	if (info->exe && access(info->exe, X_OK) == 0)
	{
		return (_execute(info));
	}
	if (info->exe)
	{
		perrorl_default(*info->argv, info->lineno, "Permission denied",
				*info->tokens, NULL);
		info->status = 126;
	}
	else
	{
		perrorl_default(*info->argv, info->lineno, "not found",
				*info->tokens, NULL);
		info->status = 127;
	}
	return (info->status);
}


/**
 * _execute - fork and exec the current command
 * @info: shell information
 *
 * Return: exit status of the child process
 */
int _execute(info_t *info)
{
	char *exe, **argv, **env;

	switch (fork())
	{
	case 0:
		exe = info->exe;
		argv = info->tokens;
		env = dict_to_env(info->env);

		info->exe = NULL;
		info->tokens = NULL;
		free_info(info);

		execve(exe, argv, env);
		perror(*argv);

		if (info->file)
			close(info->fileno);

		free(exe);
		free_tokens(&argv);
		free_tokens(&env);
		exit(EXIT_FAILURE);
		break;
	case -1:
		perrorl_default(*info->argv, info->lineno, "Cannot fork", NULL);
		info->status = 2;
		break;
	default:
		wait(&info->status);
		info->status = WEXITSTATUS(info->status);
		break;
	}
	free(info->exe);
	info->exe = NULL;

	return (info->status);
}
