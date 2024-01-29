/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** display an int nulber with write
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";

    fichier = fopen("test.txt", "r");
    if (fichier != NULL){
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL){
            printf("%s", chaine);
        }
        fclose(fichier);
    }
    return 0;
}
