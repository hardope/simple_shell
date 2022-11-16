#include "error.h"

/**
  * perrorl - print a formatted message to standard error
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl(const char *msg, ...)
{
	const char *str;
	va_list context;

	va_start(context, msg);
	while ((str = va_arg(context, char *)))
	{
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
	}
	va_end(context);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}


/**
  * perrorl_default - print a formatted message to standard error
  * @arg0: argument vector
  * @lineno: line number
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...)
{
	char *linenostr = num_to_str(lineno);
	const char *str = NULL;
	va_list ap;

	if (arg0)
		write(STDERR_FILENO, arg0, _strlen(arg0));
	write(STDERR_FILENO, ": ", 2);

	if (linenostr)
		write(STDERR_FILENO, linenostr, _strlen(linenostr));
	write(STDERR_FILENO, ": ", 2);

	va_start(ap, msg);
	while ((str = va_arg(ap, char *)))
	{
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
	}
	va_end(ap);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	free(linenostr);
}
