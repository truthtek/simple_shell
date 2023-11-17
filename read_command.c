#include "shell.h"

/**
 * read_command - reads a command from standard input
 * @buffer: the buffer to store the command
 * @max_size: the maximum size of the buffer
 *
 * Return: 1 if successful, 0 on EOF
 */

int read_command(char *buffer, size_t max_size)
{
	if (getline(&buffer, &max_size, stdin) == EOF)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);/* Handle EOF (Ctrl+D) */
	}
	buffer[strcspn(buffer, "\n")] = '\0';/* Remove the newline character */
	return (1);
}
