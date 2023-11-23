/*
** EPITECH PROJECT, 2023
** pool day03
** File description:
** info
*/
#include <stdio.h>
#include "my.h"

long print_it2(double num, char *signe, long exponent)
{
    long cpt;

    cpt = my_print_float(num);
    my_putchar('e');
    my_putstr(signe);
    if (exponent < 10) {
        my_put_nbr(0);
    }
    my_put_nbr(exponent);
    return cpt + 4;
}

long science_e(double num)
{
    long exponent = 0;
    char *signe;

    while (num < 1.0) {
        num *= 10;
        exponent--;
        signe = "-";
    }
    while (num >= 10.0) {
        num /= 10;
        exponent++;
        signe = "+";
    }
    return print_it2(num, signe, exponent);
}
