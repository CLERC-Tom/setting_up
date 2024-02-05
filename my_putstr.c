/*
** EPITECH PROJECT, 2023
** Day03_Pool_1rst_Year
** File description:
** function that swap two int values
*/
#include "my.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int my_putstr(char const *str)
{
    write(1, str, str_len(str));
    return 0;
}
