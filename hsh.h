#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#include "alias.h"
#include "builtins.h"
#include "command.h"
#include "ctype.h"
#include "dict.h"
#include "env.h"
#include "error.h"
#include "info.h"
#include "list.h"
#include "path.h"
#include "quote.h"
#include "string.h"
#include "tokens.h"
#include "types.h"

extern char **environ;

bool read_input(info_t *info);
quote_state_t _read_input(char **lineptr, int fd);

int parse(info_t *info);

int execute(info_t *info);
int _execute(info_t *info);

void expand_aliases(alias_t *aliases, char ***tokptr);
char *expand_alias(alias_t *aliases, char ***tokptr);

void expand_vars(info_t *info, char ***tokptr);
char **_expand_vars(info_t *info, char ***tokptr);

void remove_comments(cmdlist_t *cmd);

void open_script(info_t *info);

void _sigint(int signal);

#endif /* SHELL_H */
