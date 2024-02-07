/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

static int count_lines2(char *str)
{
    int count = 0;

    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (str[i] == '\n')
            count++;
    }
    return count;
}

static int count_char(char *str)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            count = j > count ? j : count;
            j = 0;
        } else {
            j++;
        }
        i++;
    }
    return count;
}

char **str_to_wordarray(char *str)
{
    int lines = count_lines2(str);
    int count_c = count_char(str);
    int j = 0;
    int i = 0;
    int count = 0;
    char **array = malloc(sizeof(char *) * (lines + 1));

    while (str[count] != '\0') {
        array[j] = malloc(sizeof(char) * (count_c + 1));
        while (str[count] != '\0' && str[count] != '\n') {
            array[j][i] = str[count];
            i++;
            count ++;
        }
        array[j][i] = '\0';
        j++;
        count++;
        i = 0;
    }
    array[lines] = NULL;
    return array;
}

int bigger_square(param *map, int i, int j, int size)
{
    if (map->max_carre < size) {
        map->max_carre = size;
        map->xmax = i;
        map->ymax = j;
    }
    return 0;
}
int check_left(param *map, int x, int y, int size)
{
    for (int i = 0; i < size; i++)
    {
        x --;
        if (map->tab[y][x] == 'o')
        {
            return 1;
        }
    }
    return 0;
}

int check_top(param *map, int x, int y, int size)
{
    for (int i = 0; i < size; i++)
    {
        y --;
        if (map->tab[y][x] == 'o')
        {
            return 1;
        }
    }
    return 0;
}

int algo_diago(param *map, int x, int y, int size)
{
    x ++;
    y ++;

    if (map->tab[y] && map->tab[y][x] && map->tab[y][x] == '.') {
        if (check_left(map, x, y, size) == 0 && check_top(map, x, y, size) == 0) {
            size ++;
            return algo_diago(map, x, y, size);
        }
    }
    return size;
}

void remplace_x(param *map, int x, int y)
{
    for (int i = x; i < x + map->max_carre; i++) {
        for (int j = y; j < y + map->max_carre; j++) {
            map->tab[i][j] = 'x';
        }
    }
}

void print_map(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putstr("\n");
    }
}
