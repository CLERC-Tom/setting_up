/*
** EPITECH PROJECT, 2023
** epitech_pool_day09
** File description:
** file that contains all prototypes
*/
#ifndef MY_H
    #define MY_H

typedef struct {
    int mx;
    int mxs;
    int msc;
} BigsqParams;



void my_putchar(char c);
int my_strcmp(char *s1, char *s2);
long my_put_nbr(long n);
char *my_strcpy(char *dest, char const *src);
long my_putstr(char const *str);
long my_strlen(char const *str);
void ls_a(void);
int my_printf(const char *format, ...);
static int count_verif(const char *p, const char *r);
void genesq(char **file, int rows, int cols);
void matrice(int i, int j, BigsqParams *p, int **dp);
void prevoit(int **dp, char **file, int rows, int cols);
void bigsq(char **file, int rows, int cols, BigsqParams *p);

#endif /* MY_H */
