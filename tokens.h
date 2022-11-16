#ifndef TOKENS_H
#define TOKENS_H

#include <stdlib.h>
#include "quote.h"
#include "string.h"

char **tokenize(const char *str);
char **tokenize_noquote(const char *str);

size_t count_tokens(const char *str);
size_t count_tokens_noquote(const char *str);

void free_tokens(char ***tokens);

char **arrdup(char **arr);

char **arrjoin(char **arr1, char **arr2);

#endif /* TOKENS_H */
