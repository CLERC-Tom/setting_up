/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] > s2[i]){
            return (1);
        }
        if (s1[i] < s2[i]){
            return (-1);
        }
    i++;
    }
    return (0);
}
