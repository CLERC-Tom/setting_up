/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** display an int nulber with write
*/
#include <unistd.h>
#include "my.h"

long my_put_nbr(long n)
{
    long a;
    long rd;

    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    if (n > 9) {
        a = n / 10;
        n -= 10 * a;
        my_put_nbr(a);
    }
    rd = '0' + n;
    write(1, &rd, 1);
    return 0;
}
