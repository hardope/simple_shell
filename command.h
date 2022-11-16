#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <stdlib.h>
#include "quote.h"
#include "string.h"
#include "tokens.h"
#include "types.h"

/**
 * enum cmdlist_sep_n - numeric values for commmand list separators
 * @SEMICOLON: ;
 * @AMPERSAND: &
 * @AND: &&
 * @OR: ||
 */
typedef enum cmdlist_sep_n
{
	SEMICOLON = 1,
	AMPERSAND = 2,
	AND       = 4,
	OR        = 8
} cmdlist_sep_n_t;

/**
 * struct cmdlist_sep - command list separator structure
 * @sep: the command separator
 * @n: the corresponding numeric value
 */
typedef struct cmdlist_sep
{
	const char *sep;
	enum cmdlist_sep_n n;
} cmdlist_sep_t;

/**
 * struct cmdlist - a linked list of commands
 * @next: the next command
 * @tree: a binary tree of commands
 * @tokens: the tokens for each command in the tree
 */
struct cmdlist
{
	struct cmdlist *next;
	struct cmdtree *tree;
	char **tokens;
};

/**
 * struct cmdtree - a binary tree of commands
 * @success: the command to execute upon failure
 * @failure: the command to execute upon success
 * @tokens: a simple command with no separators
 * @sep: the preceding list separator
 */
struct cmdtree
{
	struct cmdtree *success;
	struct cmdtree *failure;
	const char * const *tokens;
	struct cmdlist_sep sep;
};

cmdlist_t *cmd_to_list(const char *cmd);
cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, char *split, size_t count);

size_t split_cmd(char *cmd);

cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd);
cmdlist_t *del_cmd(cmdlist_t **headptr, size_t index);
char **pop_cmd(cmdlist_t **headptr);
void free_cmdlist(cmdlist_t **headptr);

cmdtree_t *cmd_to_tree(const char * const *tokens);
void free_cmdtree(cmdtree_t **rootptr);

#endif /* _COMMAND_H_ */
