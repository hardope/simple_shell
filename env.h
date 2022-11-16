#ifndef _ENV_H_
#define _ENV_H_

#include <stdlib.h>
#include "dict.h"
#include "string.h"
#include "types.h"

typedef dict_t env_t;

env_t *env_to_dict(char **env);
env_t *_env_to_dict(env_t **tailptr, char **env);
char **dict_to_env(env_t *head);

#endif /* _ENV_H_ */
