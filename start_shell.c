#include "shell.h"

/**
 * start_shell - reads commands from standard input and executes them
 *
 * Return: 0 on success, or EXIT_FAILURE on failure
 */

int start_shell(void)
{
	char buffer[MAX_BUFFER];
	pid_t pid;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9); /* Display prompt */
		if (fgets(buffer, MAX_BUFFER, stdin) == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break; /* Handle EOF (Ctrl+D) */
		}
		buffer[strcspn(buffer, "\n")] = '\0'; /* Remove the newline character */

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

			if (execvp(buffer, args) == -1)
			{
				dprintf(STDERR_FILENO, "%s: No such file or directory\n", buffer);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0); /* Wait for the child process to complete */
		}
	}

	return (0);
}
