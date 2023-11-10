#include "shell.h"

/**
 * start_shell_with_args - Start shell program with arguments
 *
 * Return: 0 on success, -1 on failure
 */

int start_shell_with_args(void)
{
	char input[MAX_ARG_LENGTH];
	char *args[MAX_ARGS];
	int status;
	pid_t pid;

	while (1)
	{
		read_command(input, MAX_ARG_LENGTH); /* call function */
		tokenize_args(args, input, MAX_ARGS); /* call function */

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}
