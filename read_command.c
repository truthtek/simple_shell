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
