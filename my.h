/*
** EPITECH PROJECT, 2023
** epitech_pool_day09
** File description:
** file that contains all prototypes
*/
#include <time.h>
#include <unistd.h>

#ifndef MY_H
    #define MY_H
        #define TAILLE_MAX 1000

void my_putchar(char c);
int my_strcmp(char *s1, char *s2);
long my_put_nbr(long n);
long my_putstr(char const *str);
long my_strlen(char const *str);
void ls_a(void);
int my_printf(const char *format, ...);

#endif /* MY_H */
