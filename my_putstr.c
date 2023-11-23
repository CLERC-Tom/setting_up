/*
** EPITECH PROJECT, 2023
** Day03_Pool_1rst_Year
** File description:
** function that swap two int values
*/

#include "my.h"

long my_putstr(char const *str)
{
    long c = 0;

    while (str[c] != '\0') {
        my_putchar(str[c]);
        c = c + 1;
    }
}
