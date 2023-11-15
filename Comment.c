#include "shell.h
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

/**
 * main - Simple shell program with Betty style  
 *
 * Return: 0 on success
 */ 
int main(void)
{
char input[MAX_INPUT_SIZE];
while (1) 
{
/* Print prompt */
printf("mysh> ");
/* Read input */
fgets(input, MAX_INPUT_SIZE, stdin);
/* Remove newline from input */
input[strlen(input) - 1] = '\0';
/* Skip empty lines */ 
if (strlen(input) == 0)
{
continue;
}
/* Check for comment */
if (input[0] == '#') 
{
continue; 
}
/* Add shell commands */
}
return (0);
}
/**
 * print_prompt - Prints the shell prompt 
 *
 * Return: Void
 */
void print_prompt(void)
{
  printf("mysh> ");
}
