/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#ifndef MY_H
    #define MY_H
        #include <stdbool.h>

typedef struct struct1 {
    int lines;
    int column;
    char **tab;
    int max_courant;
    int max_carre;
    int xmax;
    int ymax;
    char *buffer;
    int max;
    int k;
    bool stop;
} param;

void my_putchar(char c);
int lenght(char *buffer);
void print_map(char **array);
int weidth(char *buffer);
void free_wordarray(char **wordtab);
char **str_to_wordarray(char *phrase);
static int count_lines2(char *str);
static int count_char(char *str);
int my_strcmp(char *s1, char *s2);
int my_put_nbr(int n);
char *my_strcpy(char *dest, char const *src);
int my_putstr(char const *str);
int str_len(const char *str);
void ls_a(void);
int my_printf(const char *format, ...);
static int count_verif(const char *p, const char *r);
int bigger_square(param *map, int i, int j, int size);
int algo_diago(param *map, int x, int y);
int parcours_map(param *map);
void remplace_x(param *map, int x, int y);
int count_characters_per_line(param *struct1, int *lil, int num_l);
int count_lines(char *fileDescriptor);
int verif_line(param *struct1);

#endif /* MY_H */
