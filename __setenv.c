#include "builtins.h"

/**
 * __setenv - sets the environment variables
 * @info: arguments passed
 *
 * Return: status
 */
int __setenv(info_t *info)
{
	env_t *var;
	char **args = info->tokens + 1, *val;

	if (args[0])
	{
		if (args[1])
		{
			if (args[2])
			{
				perrorl("Too many arguments.", *info->tokens, NULL);
				info->status = EXIT_FAILURE;
				return (info->status);
			}
			val = args[1];
		}
		else
		{
			val = "";
		}
		var = get_dict_node(info->env, args[0]);
		if (var)
		{
			free(var->val);
			var->val = _strdup(val);
		}
		else
		{
			add_dict_node_end(&info->env, args[0], val);
		}
		info->status = EXIT_SUCCESS;
	}
	else
	{
		__env(info);
	}
	return (info->status);
}
