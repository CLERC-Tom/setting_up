/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** function that display an octal number
*/
#include <stdio.h>
#include <unistd.h>
#include "my.h"

void my_print_octal(long n)
{
    long a;
    long rd;

    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    if (n > 7) {
        a = n / 8;
        n -= 8 * a;
        my_print_octal(a);
    }
    rd = '0' + n;
    write(1, &rd, 1);
}
