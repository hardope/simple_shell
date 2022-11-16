#include "builtins.h"

/**
  * __exit - exits from shell
  * @info: arguments passed
  * Return: int
  */
int __exit(info_t *info)
{
	char **args = info->tokens + 1;

	if (*args)
	{
		if (_isnumber(*args) && atou(*args) <= INT_MAX)
		{
			info->status = atou(*args);
		}
		else
		{
			perrorl_default(*info->argv, info->lineno, *args,
					*info->tokens, "Illegal number", NULL);
			info->status = 2;

			return (info->status);
		}
	}
	if (info->file)
		close(info->fileno);

	exit(free_info(info));
}
