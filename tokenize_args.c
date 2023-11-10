#include "shell.h"

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
