#include "shell.h"

/**
 * handle_builtin - Handles built-in command
 * @args: argument
 *
 * Return: 0 on success, -1 on failure
 */

int handle_builtin(char **args)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		exit_builtin();
		/* EXIT_SUCCESS; */
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		env_builtin();
		return (1);
	}
	return (0);
}
