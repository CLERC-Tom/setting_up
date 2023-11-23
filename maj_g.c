/*
** EPITECH PROJECT, 2023
** pool day03
** File description:
** info
*/

#include <unistd.h>
#include "my.h"

long get_e1_part(double num)
{
    while (num < 1.0) {
        num *= 10;
    }
    while (num >= 10.0) {
        num /= 10;
    }
    return num;
}

long get_exp(double num)
{
    long exp = 0;

    while (num < 1.0) {
        num *= 10;
        exp = exp - 1;
    }
    while (num >= 10.0) {
        num /= 10;
        exp = exp + 1;
    }
    return exp;
}

long get_intpart(double nb)
{
    return (int)nb;
}

long maj_g(double num)
{
    long taille_e;
    long taille_f;
    long exp;

    exp = get_exp(num);
    taille_f = cpt_nbr(get_intpart(num));
    taille_e = 1000000 * cpt_nbr(get_e1_part(num));
    if (exp >= -4 && exp < 6) {
        mini_printf("%d", get_intpart(num));
        return taille_f;
    }
    return my_big_science(num);
}
