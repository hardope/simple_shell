#ifndef _QUOTE_H_
#define _QUOTE_H_

#include <stdlib.h>

#include "ctype.h"
#include "string.h"

/**
 * enum quote_state - a quote state mnemonic
 * @QUOTE_NONE: In an unquoted sequence of blanks
 * @QUOTE_WORD: In an unquoted sequence of non-blanks
 * @QUOTE_DOUBLE: In double quotes
 * @QUOTE_SINGLE: In single quotes
 * @QUOTE_ESCAPE: Following a backslash
 */
typedef enum quote_state
{
	QUOTE_NONE   = 0x0,
	QUOTE_WORD   = 0x1,
	QUOTE_DOUBLE = 0x2,
	QUOTE_SINGLE = 0x4,
	QUOTE_ESCAPE = 0x8
} quote_state_t;

typedef size_t (*quote_state_fp)(const char *, quote_state_t *);

quote_state_t quote_state(char c);

quote_state_fp quote_state_f(quote_state_t s);

size_t quote_state_len(const char *str, quote_state_t state);
size_t _quote_state_none(const char *str, quote_state_t *state);
size_t _quote_state_word(const char *str, quote_state_t *state);
size_t _quote_state_double(const char *str, quote_state_t *state);
size_t _quote_state_single(const char *str, quote_state_t *state);
size_t _quote_state_escape(const char *str, quote_state_t *state);

int _isspecial_double(char c);

char *dequote(const char *str);
size_t dequote_len(const char *str);

#endif /* _QUOTE_H_ */
