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
 * execute_child_process - Execute the child process
 * @full_path: the full path to the command
 * @args: array of command arguments
 */
void execute_child_process(char *full_path, char *args[])
{
	if (execvp(full_path, args) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_command - Handle the execution of a command
 * @args: array of command arguments
 */
void handle_command(char *args[])
{

	char *full_path = NULL;

	if (args[0] != NULL)
	{
		full_path = search_path(args[0]);
	}

	if (full_path != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			exit_builtin();
		}
		else
		{
			execute_child_process(full_path, args);
		}

		free(full_path);
	}
	else
	{
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": command not found\n", 20);
		exit(EXIT_FAILURE);
	}
}

/**
 * start_shell_loop - Main loop for the shell
 */
void start_shell_loop(void)
{
	char input[MAX_ARG_LENGTH];
	char *args[MAX_ARGS];
	int status;
	pid_t pid;

	while (1)
	{
		read_command(input, MAX_ARG_LENGTH);
		tokenize_args(args, input, MAX_ARGS);

		if (handle_builtin(args))
			break;

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			handle_command(args);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
}

/**
 * start_shell_path - Start shell program with PATH handling
 *
 * Return: 0 on success, -1 on failure
 */
int start_shell_path(void)
{
	start_shell_loop();
	return (0);
}
