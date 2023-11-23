/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/

long cpt_hex(long nb)
{
    long cpt = 1;

    while (nb >= 16) {
        nb = nb / 16;
        cpt++;
    }
    return cpt;
}
