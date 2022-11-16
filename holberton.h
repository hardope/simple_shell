#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
char *read_line(void);
char **splits(char *line, char *delim);
int execute(char **parse);
void _puts(char *str);
int _putchar(char c);
unsigned int _strlen(char *s);
char **find_path(char **environ);
char *_getenv(char **environ, char *dirname);
char *args_path(char **parse, char **tokens);
char *_strdup(char *str);
char *if_exists(char **environ);
extern char **environ;
#endif
