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
        map->xmax = i + 1;
        map->ymax = j + 1;
    }
    return 0;
}

static int check_point(param *map, int x, int y, int max)
{
    int k = max + 1;

    while (k > 0) {
        if (map->tab[x + k][y + max + 1] == '.'
        && map->tab[x + max + 1][y + k] == '.') {
            k--;
        } else {
            return 0;
        }
    }
    return 1;
}

static int alentour(param *map, int x, int y, int max)
{
    int k = max + 1;

    if (map->tab[x + k] != NULL
    && map->tab[x + k][y + k] == '.') {
        return check_point(map, x, y, max);
    }
    return 0;
}

int algo_diago(param *map, int x, int y)
{
    int max = 0;
    bool stop = false;

    while (!stop && map->tab[x + max] != NULL
    && map->tab[x + max][y + max] != '\0') {
        if (alentour(map, x, y, max)) {
            max++;
        } else {
            stop = true;
        }
    }
    return max;
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
