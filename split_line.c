#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DELIMITER " \t\r\n\a"

/**
 * _getline - Read a line from standard input
 *
 * Return: The line read from standard input
 */
char *_getline(void)
{
    static char buffer[BUFFER_SIZE];
    static int buffer_index;
    int read_bytes;

    if (buffer_index == 0)
    {
        read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (read_bytes <= 0)
            return NULL;
    }

    char *line = malloc(BUFFER_SIZE * sizeof(char));
    int line_index = 0;

    while (buffer_index < read_bytes)
    {
        if (buffer[buffer_index] == '\n')
        {
            line[line_index] = '\0';
            buffer_index++;
            return line;
        }

        line[line_index++] = buffer[buffer_index++];
    }

    if (buffer_index == read_bytes)
    {
        read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (read_bytes <= 0)
        {
            line[line_index] = '\0';
            return line;
        }
        buffer_index = 0;
    }

    return line;
}

/**
 * split_line - Split a line into tokens
 * @line: The line to be split
 *
 * Return: An array of tokens
 */
char **split_line(char *line)
{
    char **tokens = malloc(BUFFER_SIZE * sizeof(char *));
    char *token;
    int token_index = 0;

    if (tokens == NULL)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIMITER);
    while (token != NULL)
    {
        tokens[token_index++] = token;
        token = strtok(NULL, DELIMITER);
    }
    tokens[token_index] = NULL;

    return tokens;
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    char *line;
    char **args;

    while (1)
    {
        printf("$ ");
        line = _getline();
        if (line == NULL)
            break;

        args = split_line(line);

        // Your code logic goes here

        free(line);
        free(args);
    }

    return 0;
}
