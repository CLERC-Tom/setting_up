/*
** EPITECH PROJECT, 2023
** Setting up
** File description:
** info
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *f;
    char c;

    f = fopen(argv[1], "r");
    if (f == NULL){
        write(1, "pas assez d'arguments\n", 22);
        exit(84);
    }
    while ((c = fgetc(f)) != EOF){
        my_printf("%c", c);
    }
    fclose(f);
    return 0;
}
