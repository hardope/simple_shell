#ifndef _INFO_H_
#define _INFO_H_

#include <stdlib.h>
#include <unistd.h>

#include "alias.h"
#include "command.h"
#include "env.h"
#include "error.h"
#include "getline.h"
#include "history.h"
#include "list.h"
#include "string.h"
#include "tokens.h"
#include "types.h"

extern char **environ;

/**
  * struct info - shell state
  * @interactive: arguments passed
  * @argc: arguments passed
  * @argv: arguments passed
  * @file: arguments passed
  * @fileno: arguments passed
  * @status: arguments passed
  * @line: arguments passed
  * @lineno: arguments passed
  * @tokens: arguments passed
  * @pid: arguments passed
  * @cwd: arguments passed
  * @exe: arguments passed
  * @env: arguments passed
  * @path: arguments passed
  * @aliases: arguments passed
  * @history: arguments passed
  * @commands: arguments passed
  */
struct info
{
	int interactive;
	int argc;
	char **argv;
	char *file;
	int fileno;
	int status;
	char *line;
	size_t lineno;
	char **tokens;
	pid_t pid;
	char *cwd;
	char *exe;
	env_t *env;
	list_t *path;
	alias_t *aliases;
	history_t *history;
	cmdlist_t *commands;
};

info_t *init_info(int argc, char **argv);
int free_info(info_t *info);

#endif /* _INFO_H_ */
