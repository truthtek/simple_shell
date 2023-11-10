#include "shell.h"

/**
 * main - calls the shell function
 *
 * Return: 0 on success
 */

int main(void)
{
	start_shell(); /* Call the simple shell function */
	start_shell_with_args(); /* Call the shell with command line arguments */
	start_shell_path(); /* Call the shell path handling */
	return (0);
}
