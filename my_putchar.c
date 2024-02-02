/*
** EPITECH PROJECT, 2023
** pool day03
** File description:
** info
*/
#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
    return;
}
