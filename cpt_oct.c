/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/

#include "my.h"

long cpt_oct(long nb)
{
    long cpt = 1;

    while (nb >= 8) {
        nb = nb / 8;
        cpt++;
    }
    return cpt;
}
