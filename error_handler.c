#include "shell.h"
/**
 * error_handler - error message handler
 * @myself: my own nam as shell.
 * @msg_code: error message number.
 */
void error_handler(char *myself, int msg_code)
{
	int i = 0, printed = 0;
	size_t size = _strlen(myself);

	error_msg_t errors[] = {
		{00, "Error unknown", 14},
		{100, "Error reading from Prompt - Zero tokens", 40},
		{101, "No such file or directory", 26},
		{102, "FATAL ERROR: UNABLE TO CREATE CHILD PROCESS", 44},
		{103, "command not found", 17},
		{104, "FATAL ERROR: NO MEMORY AVAILABLE.", 33},
		{105, "FATAL ERROR: UNABLE TO CREATE CMD LIST", 38},
		{999, "", 0} /* Error Array end condition*/
	};

	write(STDERR_FILENO, myself, size);
	write(STDERR_FILENO, ": ", 2);
	while (errors[i].ecode != 999)
	{
		if (errors[i].ecode == msg_code)
		{
			write(STDERR_FILENO, errors[i].msg, errors[i].size);
			printed = 1;
		}
		i++;
	}
	if (!printed)
		write(STDERR_FILENO, errors[0].msg, errors[0].size);
	write(STDERR_FILENO, "\n", 1);
}
