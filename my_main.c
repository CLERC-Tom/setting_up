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

int count_lines(const char *filename)
{
    struct stat fileStat;
    int lineCount = 0;
    int c;
    FILE *file = fopen(filename, "r");

    if (stat(filename, &fileStat) == -1) {
        perror("Erreur lors de l'appel à stat()");
        return -1;
    }
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            lineCount++;
        }
    }
    fclose(file);
    return lineCount;
}

static int init(char **argv, int *pRows, size_t *pMaxLineLength)
{
    int rows = count_lines(argv[1]);
    size_t maxLineLength = 0;
    size_t currentLength;
    char buffer[256];
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 84;
    }
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        currentLength = my_strlen(buffer);
        if (currentLength > maxLineLength) {
            maxLineLength = currentLength;
        }
    }
    fclose(file);
    *pRows = rows;
    *pMaxLineLength = maxLineLength;
    return 0;
}

int decompose(FILE *file, char **matrix, int rows, size_t maxLineLength)
{
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char *)malloc((maxLineLength + 1) * sizeof(char));
    }
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 84;
    }
    for (int i = 0; i < rows; i++) {
        if (fgets(matrix[i], maxLineLength + 1, file) == NULL) {
            perror("Erreur lors de la lecture du fichier");
            return 84;
        }
        matrix[i][strcspn(matrix[i], "\n")] = '\0';
    }
    return 0;
}

void delete_first(char **matrix, int rows)
{
    for (int i = 0; i < rows - 1; i++) {
        strcpy(matrix[i], matrix[i + 1]);
    }
    matrix[rows - 1][0] = '\0';
}

int main(int argc, char *argv[])
{
    int rows;
    size_t maxLineLength;
    FILE *file = fopen(argv[1], "r");
    int initResult = init(argv, &rows, &maxLineLength);
    char **matrix = (char **)malloc(rows * sizeof(char *));
    int decomposeResult = decompose(file, matrix, rows, maxLineLength);

    delete_first(matrix, rows);
    if (decomposeResult != 0) {
        fclose(file);
        for (int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
        return 84;
    }
    fclose(file);
    genesq(matrix, rows, maxLineLength);
    free(matrix);
    return 0;
}
