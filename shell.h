#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define MAX_ARG_LENGTH 1024

int start_shell_with_args(void);

int start_shell(void);

void prompt(void);

void execute_command(char *command);

#endif /* SHELL_H */
