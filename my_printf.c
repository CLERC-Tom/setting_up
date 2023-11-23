/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** function that reproduces printf
** behavior
*/
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include <unistd.h>

long disp_stdarg_int2(char s, va_list list, long cpt, int nb)
{
    if (s == 'u') {
        if (nb < 0) {
            write(2, "u format do not support negative numbers\n", 41);
            return -10000000;
        }
        my_put_nbr(nb);
        return cpt + cpt_nbr(nb);
    }
    if (s == 'p') {
        print_pointer(nb);
        return cpt + cpt_hex(nb) + 2;
    }
    return -100000000;
}

long disp_stdarg_int(char s, va_list list, long cpt)
{
    long nb = 0;

    nb = va_arg(list, long);
    if (s == 'i' || s == 'd') {
        my_put_nbr(nb);
        return cpt + cpt_nbr(nb);
    }
    if (s == 'x') {
        my_print_hexa(nb);
        return cpt + cpt_hex(nb);
    }
    if (s == 'X') {
        my_print_hexa_capped(nb);
        return cpt + cpt_hex(nb);
    }
    if (s == 'o') {
        my_print_octal(nb);
        return cpt + cpt_oct(nb);
    }
    return disp_stdarg_int2(s, list, cpt, nb);
}

long disp_stdarg_float(double nbr, char s)
{
    if (s == 'f') {
        return my_print_float(nbr);
    }
    if (s == 'e') {
        return science_e(nbr);
    }
    if (s == 'E') {
        return my_big_science(nbr);
    }
    if (s == 'g') {
        return min_g(nbr);
    }
    if (s == 'G') {
        return maj_g(nbr);
    }
    return -10000000;
}

long disp_stdarg(char s, va_list list, long cpt)
{
    char ch;
    char *str;
    double nbr;

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
    if (s == 'f' || s == 'e' || s == 'E' || s == 'g' || s == 'G') {
        nbr = va_arg(list, double);
        return cpt + disp_stdarg_float(nbr, s);
    }
    return disp_stdarg_int(s, list, cpt);
}

static long tests(va_list list, long i, long cpt, const char *format)
{
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] == '%') {
            write(1, "%", 1);
            i = i + 2;
            cpt++;
        }
        if (format[i] == '%' && format[i + 1] == 'n') {
            i = i + 2;
        }
        if (format[i] == '%' && format[i + 1] != '%' && format[i + 1] != 'n') {
            cpt = disp_stdarg(format[i + 1], list, cpt);
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

long my_printf(const char *format, ...)
{
    va_list list;
    long i = 0;
    long cpt = 0;

    va_start(list, format);
    cpt = tests(list, i, cpt, format);
    va_end(list);
    return cpt;
}
