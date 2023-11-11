#include "shell.h"

/**
 * exit_builtin - Handle the exit built-in command
 *
 * Return: 0 on success, -1 on failure
 */

void exit_builtin(void)
{
	exit(EXIT_SUCCESS);
}
