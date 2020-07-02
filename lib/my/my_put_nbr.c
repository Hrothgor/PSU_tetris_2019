/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_putchar(char);
void my_putstr(char *);

int my_put_nbr(int nb)
{
    int	nb_bis = nb;
    int affichage = 0;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb_bis < 0) {
        my_putchar('-');
        my_put_nbr(-nb_bis);
    }
    affichage = nb % 10;
    nb_bis = nb / 10;
    if (nb_bis > 0)
        my_put_nbr(nb_bis);
    if (affichage >= 0)
        my_putchar(affichage + 48);
    return (0);
}
