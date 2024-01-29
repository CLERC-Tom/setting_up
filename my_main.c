/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** display an int number with write
*/
#include <stdio.h>
#include <string.h>
#include "my.h"

static int min(int a, int b, int c)
{
    int minimum = a;

    if (b < minimum){
        minimum = b;
    }
    if (c < minimum){
        minimum = c;
    }
    return minimum;
}

static void condition(int i, int j, BigsqParams *p, char file[ML][MC])
{
    if (i >= p->mxs - p->mx + 1 && i <= p->mxs &&
        j >= p->msc - p->mx + 1 && j <= p->msc) {
        my_printf("x");
    } else {
        my_printf("%c", file[i][j]);
    }
}

void bigsq(char file[ML][MC], int rows, int cols, BigsqParams *p)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            condition(i, j, p, file);
        }
        my_printf("\n");
    }
}

void prevoit(int dp[ML][MC], char file[ML][MC], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        dp[i][0] = (file[i][0] == 'o') ? 0 : 1;
    for (int j = 0; j < cols; ++j)
        dp[0][j] = (file[0][j] == 'o') ? 0 : 1;
    for (int i = 1; i < rows; ++i)
        for (int j = 1; j < cols; ++j)
            dp[i][j] = (file[i][j] == 'o') ? 0
            : min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
}

void matrice(int i, int j, BigsqParams *p, int dp[ML][MC])
{
    if (dp[i][j] > p->mx) {
        p->mx = dp[i][j];
        p->mxs = i;
        p->msc = j;
    }
}

void genesq(char file[ML][MC], int rows, int cols)
{
    int dp[ML][MC];
    int mx = 0;
    int mxs = 0;
    int msc = 0;
    BigsqParams p = {0, 0, 0};

    prevoit(dp, file, rows, cols);
    for (int i = 1; i < rows; ++i){
        for (int j = 1; j < cols; ++j){
            dp[i][j] = (file[i][j] == 'o') ? 0
            : min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            matrice(i, j, &p, dp);
        }
    }
    bigsq(file, rows, cols, &p);
}

static int count_verif(const char *p, const char *r)
{
    if (*p == *r) {
        return 1;
    } else {
        return 0;
    }
}

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
}

main(int argc, char *argv[])
{
    char matrix[ML][MC];
    FILE *file = fopen(argv[1], "r");
    int rows = 0;
    int cols = 0;

    if (argc != 2){
        return 0;
    }
    while (fgets(matrix[rows], MC, file)){
        matrix[rows][my_strcspn(matrix[rows], "\n")] = '\0';
        cols = my_strlen(matrix[rows]);
        rows++;
    }
    fclose(file);
    genesq(matrix, rows, cols);
    return 0;
}
