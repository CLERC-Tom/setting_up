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


int count_characters_per_line(param *struct1, int *lil, int num_l)
{
    int line = 0;
    int char_count = 0;

    if (!struct1 || !struct1->buffer || num_l <= 0 || !lil)
        return -1;
    for (int i = 0; struct1->buffer[i] != '\0'; ++i) {
        if (struct1->buffer[i] == '\n') {
            lil[line] = char_count;
            char_count = 0;
            ++line;
        } else {
            ++char_count;
        }
    }
    if (char_count > 0 && line < num_l) {
        lil[line] = char_count;
    }
    return 0;
}

int verif_line(param *struct1)
{
    int n_lignes = count_lines(struct1->buffer);
    int *taille = malloc(n_lignes * sizeof(int));

    if (taille == NULL) {
        return 84;
    }
    if (count_characters_per_line(struct1, taille, n_lignes) != 0) {
        return 84;
    }
    for (int i = 1; i < n_lignes - 1; ++i) {
        if (taille[i] != taille[i - 1]) {
            return 84;
        }
    }
    return 0;
}

