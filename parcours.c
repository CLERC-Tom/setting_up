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

void parcours_carre(param *map, int i, int j)
{
    int tmp;

    if (map->tab[i][j] == '.') {
        tmp = algo_diago(map, i, j);
        bigger_square(map, i, j, tmp);
    }
}

void parcours_diagonale(param *map, int i)
{
    int j = 0;

    while (map->tab[i][j] != '\0') {
        parcours_carre(map, i, j);
        j++;
    }
}

int parcours_map(param *map)
{
    int i = 1;

    while (map->tab[i] != NULL) {
        parcours_diagonale(map, i);
        i++;
    }
    return 0;
}
