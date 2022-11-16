#include "builtins.h"

/**
 * __exec - replace the running shell with a new program
 * @info: arguments passed
 * Return: int
 */
int __exec(info_t *info)
{
	char *exe, **args = info->tokens + 1, **env = NULL;

	if (!*args)
		return ((info->status = EXIT_SUCCESS));

	info->tokens = args;
	args = arrdup(args);

	if (_strchr(*args, '/') == -1)
	{
		free_list(&info->path);
		info->path = str_to_list(get_dict_val(info->env, "PATH"), ':');
		exe = search_path(info, info->path);
	}
	else
	{
		exe = _strdup(*args);
	}
	info->tokens -= 1;

	if (access(exe, X_OK) == 0)
	{
		env = dict_to_env(info->env);

		free_info(info);
		execve(exe, args, env);
		perrorl_default(*info->argv, info->lineno, "Not found",
				*info->tokens, *args, NULL);
		free(exe);
		free_tokens(&args);
		free_tokens(&env);
		exit(127);
	}
	perrorl_default(*info->argv, info->lineno, "Permission denied",
			*info->tokens, *args, NULL);
	free(exe);
	free_tokens(&args);
	free_info(info);
	exit(126);
}
