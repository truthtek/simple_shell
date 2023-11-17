#include "shell.h"

/**
 * execute_command - executes a command
 * @buffer: the command to execute
 *
 * Return: 0 on success, or EXIT_FAILURE on failure
 */

int execute_command(char *buffer)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[2];

		args[0] = buffer;
		args[1] = NULL;

		if (execve(buffer, args, NULL) == -1)
		{
			perror(buffer);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);/* Wait for the child process to complete */
	}

	return (status);
}
