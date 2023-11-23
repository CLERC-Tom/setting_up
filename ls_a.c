/*
** EPITECH PROJECT, 2023
** pool day03
** File description:
** info
*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include "my.h"

void ls_a(void)
{
    DIR *dir = opendir(".");
    struct dirent *entry;

    if (dir == NULL) {
        perror("Erreur");
        return;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        my_printf("%s  ", entry->d_name);
        entry = readdir(dir);
    }
    closedir(dir);
}
