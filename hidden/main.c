#include "shell.h"

/**
 * main - reads commands from standard input and executes them
 *
 * Return: 0 on success, or EXIT_FAILURE on failure
 */

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	while (1)
	{
		prompt(); /* Display prompt */

		if (getline(&command, &bufsize, stdin) == -1)
		{
			/* Handle error */
			free(command);
			exit(EXIT_FAILURE);
		}

		execute_command(command); /* Execute the entered command */

		free(command);
		command = NULL;
	}

	return (0);
}
