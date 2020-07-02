/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    while (src[i] != '\0')
        i++;
    str = malloc(sizeof(char) * i);
    for (int j = 0; j < i; j++)
        str[j] = src[j];
    str[i] = '\0';
    return (str);
}
