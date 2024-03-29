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

int max(param *map, int x, int y, int size)
{
    size = 0;
    if (map->tab[y][x] == '.') {
        size ++;
        return algo_diago(map, x, y, size);
    }
    return 0;
}

int parcours_map(param *map)
{
    int size = 0;

    for (int y = 0; map->tab[y] != NULL; y++) {
        for (int x = 0; map->tab[y][x] != '\0'; x++) {
            size = max(map, x, y, size);
            bigger_square(map, x, y, size);
        }
    }
    return 0;
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
