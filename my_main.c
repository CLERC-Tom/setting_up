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

int count_lines(char *fileDescriptor)
{
    int count = 1;
    int i = 0;

    while (fileDescriptor[i] != '\0') {
        if (fileDescriptor[i] == '\n') {
            count++;
        }
        i++;
    }
    return count;
}

int init(char **argv, param *struct1)
{
    int fd = open(argv[1], O_RDONLY);
    struct stat st;

    stat(argv[1], &st);
    struct1->buffer = malloc(st.st_size);
    if (fd < 0) {
        return 84;
    }
    fd = read(fd, struct1->buffer, st.st_size);
    if (fd < 0) {
        return 84;
    }
    close(fd);
    return 0;
}

int decompose(int fileDescriptor, char **matrix, int rows, size_t mxll)
{
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char *)malloc((mxll + 1) * sizeof(char));
    }
    for (int i = 0; i < rows; i++) {
        matrix[i][my_strcspn(matrix[i], "\n")] = '\0';
    }
    return 0;
}

static int skip(param *struct1)
{
    char *saut = my_strchr(struct1->buffer, '\n');

    if (saut != NULL) {
        struct1->buffer = saut + 1;
        return 0;
    } else {
        return -1;
    }
}

static int my_atoi(const char *str)
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

static int line_number(char *str, int n)
{
    for (int h = 0; str[h] != '\n'; h++) {
        if (str[h] < '0' || str[h] > '9')
            return 84;
    }
    if (my_atoi(str) != n - 1)
        return 84;
    return 0;
}

static int error_handler(char *str)
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

int main(int argc, char *argv[])
{
    param *struct1 = NULL;
    size_t mxll;
    int rows;
    char *map;

    if (argc != 2) {
        return 84;
    }
    struct1 = malloc(sizeof(param));
    if (init(argv, struct1) == 84 || error(struct1->buffer))
        return 84;
    if (init(argv, struct1) == 0 || error(struct1->buffer))
        return 84;
    skip(struct1);
    struct1->max_carre = 0;
    struct1->tab = str_to_wordarray(struct1->buffer);
    parcours_map(struct1);
    remplace_x(struct1, struct1->xmax, struct1->ymax);
    print_map(struct1->tab);
    return 0;
}

