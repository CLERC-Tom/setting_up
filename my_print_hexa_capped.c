/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** function that display an hexa number with caps
*/
#include <unistd.h>
#include "my.h"

void my_print_hexa_capped(long n)
{
    long a;
    long rd;

    if (n > 15) {
        a = n / 16;
        n -= 16 * a;
        my_print_hexa_capped(a);
    }
    if (n < 10) {
        rd = '0' + n;
    } else {
        rd = 'A' - 10 + n;
    }
    write(1, &rd, 1);
}
