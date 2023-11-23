/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** function that reproduces printf
** behavior
*/
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"

long disp_stdarg1(char s, va_list list, long cpt)
{
    long nb = 0;
    char ch;
    char *str;

    if (s == 'c') {
        ch = va_arg(list, long);
        my_putchar(ch);
        return cpt + 1;
    }
    if (s == 's') {
        str = va_arg(list, char *);
        my_putstr(str);
        return cpt + my_strlen(str);
    }
    if (s == 'i' || s == 'd') {
        nb = va_arg(list, long);
        my_put_nbr(nb);
        return cpt + cpt_nbr(nb);
    }
    return -100000000;
}

long tests(va_list list, long i, long cpt, const char *format)
{
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] == '%') {
            write(1, "%", 1);
            i = i + 2;
            cpt++;
        }
        if (format[i] == '%' && format[i + 1] != '%') {
            cpt = disp_stdarg1(format[i + 1], list, cpt);
            i = i + 2;
        }
        if (format[i] != '%' && i < my_strlen(format)) {
            write(1, &format[i], 1);
            i++;
            cpt++;
        }
    }
    return cpt;
}

long mini_printf(const char *format, ...)
{
    va_list list;
    long i = 0;
    long cpt = 0;

    va_start(list, format);
    cpt = tests(list, i, cpt, format);
    va_end(list);
    return cpt;
}
