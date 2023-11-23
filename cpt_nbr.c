/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/

#include "my.h"

long cpt_nbr(long nb)
{
    long cpt = 1;

    if (nb < 0) {
        nb = -nb;
        cpt++;
    }
    while (nb >= 10) {
        nb = nb / 10;
        cpt++;
    }
    return cpt;
}
