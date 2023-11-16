#include "shell.h"

#define MAX_INPUT_LENGTH 100

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
char input[MAX_INPUT_LENGTH];
pid_t pid;
while (1)
{
printf("#cisfun$ ");
if (fgets(input, sizeof(input), stdin) == NULL)
break;
input[strcspn(input, "\n")] = '\0';
if (strcmp(input, "exit") == 0)
break;
pid = fork();
if (pid == 0)
{
execlp(input, input, (char *)NULL);
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
