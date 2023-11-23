/*
** EPITECH PROJECT, 2023
** pool day03
** File description:
** info
*/
#include <stdio.h>
#include <unistd.h>
#include "my.h"

long print_pointer(long *ptr)
{
    my_putstr("0x");
    my_print_hexa(ptr);
}
