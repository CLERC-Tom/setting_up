/*
** EPITECH PROJECT, 2023
** epitech_pool_day09
** File description:
** file that contains all prototypes
*/
#ifndef MY_H
    #define MY_H

typedef struct struct1{
    int lines;
    int column;
    char **tab;
    int max_courant;
    int max_carre;
    int xmax;
    int ymax;
    char *buffer;
} param;

void my_putchar(char c);
int lenght(char *buffer);
void print_map(char **array);
int weidth(char *buffer);
void free_wordarray(char **wordtab);
char **str_to_wordarray(char *phrase);
int count_lines2(char *str);
int count_char(char *str);
int my_strcmp(char *s1, char *s2);
int my_put_nbr(int n);
char *my_strcpy(char *dest, char const *src);
long my_putstr(char const *str);
int str_len(const char *str);
void ls_a(void);
int my_printf(const char *format, ...);
static int count_verif(const char *p, const char *r);
int bigger_square(param *map, int i, int j, int size);
int algo_diago(param *map, int x, int y);
int parcours_map(param *map);
void remplace_x(param *map, int x, int y);

#endif /* MY_H */
