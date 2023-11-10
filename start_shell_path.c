#include "shell.h"

/**
 * search_path - Search for a command in the PATH environment variable
 * @command: the command to search for
 *
 * Return: the full path to the command if found, NULL otherwise
 */

char *search_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *full_path = malloc(MAX_PATH_LENGTH);

	while (token != NULL)
	{
		snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		token = strtok(NULL, ":");
	}

	free(path_copy);
	free(full_path);
	return (NULL);
}

/**
 * start_shell_path - Start shell program with PATH handling
 *
 * Return: 0 on success, -1 on failure
 */

int start_shell_path(void)
{
	char input[MAX_ARG_LENGTH];
	char *args[MAX_ARGS];
	int status;
	char *full_path;
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
			full_path = search_path(args[0]);
			if (full_path != NULL && execv(full_path, args) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			else if (full_path == NULL)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
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
