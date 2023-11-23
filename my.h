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

void my_putchar(char c);
int my_strcmp(char *s1, char *s2);
long my_put_nbr(long n);
long my_putstr(char const *str);
long my_strlen(char const *str);
void my_print_octal(long n);
void my_print_hexa_capped(long n);
void my_print_hexa(long n);
long my_print_float(double nb);
long my_big_science(double num);
long science_e(double num);
long print_pointer(long *ptr);
long printWithCount(const char *format, ...);
long mini_printf(const char *format, ...);
long cpt_nbr(long nb);
long cpt_hex(long nb);
long cpt_oct(long nb);
long min_g(double num);
long maj_g(double num);
int temps(const void *a, const void *b);
void ls_a(void);
char list_current_directory(void);

#endif /* MY_H */
