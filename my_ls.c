/*
** EPITECH PROJECT, 2023
** pool day03
** File description:
** info
*/
#include <stdio.h>
#include <string.h>
#include "my.h"

int ls_ls(int argc, char *argv[])
{
    const char *specifier = argv[1];

    if (argc != 2) {
        write(2, "erreur", 6);
        return 84;
    }
    if (my_strcmp(specifier, "-a") == 0) {
        ls_a();
        }
    return 0;
}
