/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int skip(param *struct1)
{
    char *saut = my_strchr(struct1->buffer, '\n');

    if (saut != NULL) {
        struct1->buffer = saut + 1;
        return 0;
    } else {
        return -1;
    }
}

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    while (*str == ' ') {
        str++;
    }
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return sign * result;
}

int line_number(char *str, int n)
{
    for (int h = 0; str[h] != '\n'; h++) {
        if (str[h] < '0' || str[h] > '9')
            return 84;
    }
    if (my_atoi(str) != n - 1)
        return 84;
    return 0;
}

int error(char *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            n++;
        }
        if (n >= 1 && str[i] != '.' && str[i] != 'o'
        && str[i] != '\n') {
            return 84;
        }
    }
    return line_number(str, n);
}
