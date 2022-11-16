#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "string.h"

void perrorl(const char *msg, ...);
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...);

#endif /* _ERROR_H_ */
