#include "shell.h"

/**
 * start_shell - reads commands from standard input and executes them
 *
 * Return: 0 on success, or EXIT_FAILURE on failure
 */

int start_shell(void)
{
	char buffer[MAX_BUFFER];

	while (1)
	{
		print_prompt();

		if (!read_command(buffer, MAX_BUFFER))
			break;

		if (buffer[0] != '\0')
			execute_command(buffer);
	}

	return (0);
}
