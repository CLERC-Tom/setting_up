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

char *my_strchr(const char *str, int c)
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
    if (fd <= 0) {
        return 84;
    }
    if (fd < st.st_size) {
        return 84;
    }
    close(fd);
    return 0;
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
    if (init(argv, struct1) == 84 || error(struct1->buffer) == 84)
        return 84;
    skip(struct1);
    if (verif_line(struct1) == 84)
        return 84;
    struct1->max_carre = 0;
    struct1->tab = str_to_wordarray(struct1->buffer);
    parcours_map(struct1);
    remplace_x(struct1, struct1->xmax, struct1->ymax);
    print_map(struct1->tab);
    return 0;
}
