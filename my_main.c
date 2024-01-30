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

static char *my_strchr(const char *str, int c)
{
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

size_t my_strcspn(const char *str, const char *chars)
{
    size_t len = 0;

    while (str[len] != '\0' && my_strchr(chars, str[len]) == NULL) {
        len++;
    }
    return len;
}

int count_lines(const char *filename)
{
    int fileDescriptor = open(filename, O_RDONLY);
    char buffer[1];
    int lineCount = 0;
    ssize_t bytesRead;

    while ((bytesRead = read(fileDescriptor, buffer, 1)) > 0) {
        if (buffer[0] == '\n') {
            lineCount++;
        }
    }
    if (bytesRead == -1) {
        perror("Erreur lors de la lecture du fichier");
        close(fileDescriptor);
        return -1;
    }
    close(fileDescriptor);
    return lineCount;
}

static int init(char **argv, int *pRows, size_t *pMaxLineLength)
{
    int fileDescriptor = open(argv[1], O_RDONLY);
    int rows = count_lines(argv[1]);
    size_t mxll = 0;
    size_t currentLength;
    char buffer[256];
    char *newlinePos;

    while (read(fileDescriptor, buffer, sizeof(buffer)) > 0) {
        char *newlinePos = my_strchr(buffer, '\n');
        if (newlinePos != NULL) {
            currentLength = newlinePos - buffer;
            if (currentLength > mxll) {
                mxll = currentLength;
            }
        }
    }
    close(fileDescriptor);
    *pRows = rows;
    *pMaxLineLength = mxll;
    return 0;
}

int decompose(int fileDescriptor, char **matrix, int rows, size_t mxll)
{
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char *)malloc((mxll + 1) * sizeof(char));
    }
    for (int i = 0; i < rows; i++) {
        if (read(fileDescriptor, matrix[i], mxll + 1) == -1) {
            perror("Erreur lors de la lecture du fichier");
            return 84;
        }
        matrix[i][my_strcspn(matrix[i], "\n")] = '\0';
    }
    return 0;
}

void delete_first(char **matrix, int rows)
{
    for (int i = 0; i < rows - 1; i++) {
        my_strcpy(matrix[i], matrix[i + 1]);
    }
    matrix[rows - 1][0] = '\0';
}

int main(int argc, char *argv[])
{
    int rows;
    size_t mxll;
    int fileDescriptor = open(argv[1], O_RDONLY);
    int initResult = init(argv, &rows, &mxll);
    char **matrix = (char **)malloc(rows * sizeof(char *));
    int decomposeResult = decompose(fileDescriptor, matrix, rows, mxll);

    delete_first(matrix, rows);
    if (decomposeResult != 0) {
        close(fileDescriptor);
        for (int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
        return 84;
    }
    close(fileDescriptor);
    genesq(matrix, rows, mxll);
    free(matrix);
    return 0;
}
