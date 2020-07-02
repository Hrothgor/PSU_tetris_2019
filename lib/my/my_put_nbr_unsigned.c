/*
** EPITECH PROJECT, 2019
** my_put_nbr_unsigned.c
** File description:
** my_put_nbr_unsigned
*/

#include <unistd.h>

void my_putchar(char);

int my_put_nbr_unsigned(long int nb)
{
    long int nb_bis = nb;
    int affichage = 0;

    if (nb_bis < 0)
        my_put_nbr_unsigned(nb_bis + 4294967295);
    affichage = nb % 10;
    nb_bis = nb / 10;
    if (nb_bis > 0)
        my_put_nbr_unsigned(nb_bis);
    if (affichage >= 0)
        my_putchar(affichage + 48);
    return (0);
}
