/*
** EPITECH PROJECT, 2023
** pool day03
** File description:
** info
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

long my_n(const char *format, ...)
{
    long cp = 0;
    va_list args;

    va_start(args, format);
    while (*format) {
        if (*format == '%' && *(format + 1) == 'w') {
            va_arg(args, long *);
            format += 2;
        } else {
            my_putchar(*format);
            cp++;
            format++;
        }
    }
    va_end(args);
    return cp;
}
