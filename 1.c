#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
			break; /* End of file (Ctrl+D) */

		/* Remove the trailing newline character */
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
			break; /* Exit the shell */

		pid_t pid = fork();
		if (pid == 0)
		{
			execlp(input, input, (char*)NULL);
			printf("%s: command not found\n", input);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
