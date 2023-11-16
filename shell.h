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
#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 1024

extern char **environ;

void exit_builtin(void);

int env_builtin(void);

int handle_builtin(char **args);

void read_command(char input[], int size);

void tokenize_args(char *args[], char input[], int max_args);

int start_shell_path(void);

int start_shell_with_args(void);

int start_shell(void);

void prompt(void);

void execute_command(char *command);



int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);

char *_get_path(char **env);
int _values_path(char **arg, char **env);
char *_getline_command(void);
void _getenv(char **env);
char **_get_token(char *lineptr);
void _exit_command(char **args, char *lineptr, int _exit);
int _fork_fun(char **arg, char **av, char **env,
char *lineptr, int np, int c);
char *_strtok(char *str, const char *delim);

#endif /* SHELL_H */
