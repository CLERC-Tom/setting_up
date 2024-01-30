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

static void condition(int i, int j, BigsqParams *p, char **file)
{
    if (i >= p->mxs - p->mx + 1 && i <= p->mxs &&
        j >= p->msc - p->mx + 1 && j <= p->msc) {
        my_printf("x");
    } else {
        my_printf("%c", file[i][j]);
    }
}

void bigsq(char **file, int rows, int cols, BigsqParams *p)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            condition(i, j, p, file);
        }
        my_printf("\n");
    }
}

void prevoit(int **dp, char **file, int rows, int cols)
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

void matrice(int i, int j, BigsqParams *p, int **dp)
{
    if (dp[i][j] > p->mx) {
        p->mx = dp[i][j];
        p->mxs = i;
        p->msc = j;
    }
}

void genesq(char **file, int rows, int cols)
{
    int **dp = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++)
        dp[i] = malloc(sizeof(int) * cols);
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
    for (int i = 0; i < rows; i++)
        free(dp[i]);
    free(dp);
}

static int count_verif(const char *p, const char *r)
{
    if (*p == *r) {
        return 1;
    } else {
        return 0;
    }
}