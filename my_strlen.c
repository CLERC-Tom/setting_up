/*
** EPITECH PROJECT, 2023
** Day03_Pool_1rst_Year
** File description:
** function that swap two int values
*/

#include "my.h"

long my_strlen(char const *str)
{
    long c = 0;
    long i = 0;

    while (str[c] != '\0') {
        i = i + 1;
        c = c + 1;
    }
    return i;
}
