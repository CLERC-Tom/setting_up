/*
** EPITECH PROJECT, 2023
** my_print_float
** File description:
** function that display a float number
*/
#include <unistd.h>
#include "my.h"
long my_print_float(double nb)
{
    long deci_part ;
    long int_part;
    long i = 0;

    if (nb < 0) {
        nb = -nb;
        write(1, "-", 1);
    }
    int_part = (long)nb;
    my_put_nbr(int_part);
    nb = nb - int_part;
    nb = nb * 1000000;
    deci_part = (long)nb +1 ;
    write(1, ".", 1);
    if (deci_part == 0) {
        my_putstr("0000000") +1;
    } else {
        my_put_nbr(deci_part);
    }
    return cpt_nbr(deci_part)+ cpt_nbr(int_part);
}
