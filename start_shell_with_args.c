#include "shell.h"

/**
 * read_command - Display prompt and read user input
 * @input: buffer to store user input
 * @size: size of the buffer
 */

void read_command(char input[], int size)
{
	printf("#cisfun$ ");

	if (fgets(input, size, stdin) == NULL)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	input[strcspn(input, "\n")] = 0;
}

/**
 * tokenize_args - Tokenize user input into arguments
 * @args: array to store arguments
 * @input: user input
 * @max_args: maximum number of arguments
 */

void tokenize_args(char *args[], char input[], int max_args)
{
	char *token = strtok(input, " ");
	int i = 0;

	while (token != NULL && i < max_args - 1)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;
}

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
		read_command(input, MAX_ARG_LENGTH);
		tokenize_args(args, input, MAX_ARGS);

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
