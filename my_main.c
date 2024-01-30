/*
** EPITECH PROJECT, 2023
** setting up
** File description:
** algo de base
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "my.h"

static int my_strcspn(const char *str, const char *reject)
{
    int count = 0;

    for (const char *p = str; *p != '\0'; p++) {
        for (const char *r = reject; *r != '\0'; r++) {
            if (count_verif(p, r)) {
                return count;
            }
        }
        count++;
    }
    return count;
    return 0;
}

int main(int argc, char *argv[])
{
    char **matrix = NULL;
    int file = open(argv[1], O_RDONLY);
    int rows = 0;
    int cols = 0;
    char buffer[1024];
    char *line = NULL;
    size_t len = 0;
    ssize_t bytesRead;
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    while ((bytesRead = read(file, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';
        char *start = buffer;
        char *end;
        while ((end = strchr(start, '\n')) != NULL) {
            *end = '\0';
            line = realloc(line, len + end - start + 1);
            strncpy(line + len, start, end - start + 1);
            len += end - start;
            line[len] = '\0';
            matrix = realloc(matrix, sizeof(char *) * (rows + 1));
            matrix[rows] = malloc(sizeof(char) * (len + 1));
            strcpy(matrix[rows], line);
            cols = strlen(matrix[rows]);
            rows++;
            start = end + 1;
            len = 0;
        }
        if (*start) {
            line = realloc(line, len + bytesRead - (start - buffer) + 1);
            strncpy(line + len, start, bytesRead - (start - buffer));
            len += bytesRead - (start - buffer);
        }
    }
    if (len > 0) {
        matrix = realloc(matrix, sizeof(char *) * (rows + 1));
        matrix[rows] = malloc(sizeof(char) * (len + 1));
        strcpy(matrix[rows], line);
        cols = strlen(matrix[rows]);
        rows++;
    }
    close(file);
    genesq(matrix, rows, cols);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(line);

    return 0;
}