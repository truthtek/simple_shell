#include "shell.h"

/**
 * read_command - Display prompt and read user input
 * @input: buffer to store user input
 * @size: size of the buffer
 */

void read_command(char input[], int size)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);

	if (fgets(input, size, stdin) == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}

	input[strcspn(input, "\n")] = 0;
}
