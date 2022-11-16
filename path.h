#ifndef PATH_H
#define PATH_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "info.h"
#include "list.h"
#include "string.h"
#include "types.h"

char *search_path(info_t *info, list_t *path);

#endif /* PATH_H */
