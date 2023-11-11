#include "shell.h"

/**
 * env_builtin - Handle the env built-in command
 *
 * Return: 0 on success, -1 on failure
 */

int env_builtin(void)
{
	extern char **environ;

	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
	       	env++;
	}
	return (0);
}
