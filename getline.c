#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

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
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    char *line;

    while (1)
    {
        printf("$ ");
        line = _getline();
        if (line == NULL)
            break;
        
        // Your code logic goes here
        
        free(line);
    }

    return 0;
}
