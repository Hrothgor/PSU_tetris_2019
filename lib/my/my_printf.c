/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../../include/my.h"

typedef struct my_print {
    char c;
    void (*func)(va_list);
} t_my_print;

static const t_my_print tabl[] =
{
    {'i', &print_int},
    {'d', &print_int},
    {'%', &print_modulo},
    {'u', &print_unsigned_int},
    {'s', &print_str},
    {'c', &print_car},
    {'\0', NULL},
};

void tableau(char c, va_list argv)
{
    int check = 0;

    for (int i = 0; tabl[i].c != '\0'; i++) {
        if (c == tabl[i].c) {
            tabl[i].func(argv);
            check = 1;
        }
    }
    if (check == 0) {
        my_putchar('%');
        my_putchar(c);
    }
}

void my_printf(char *str, ...)
{
    va_list argv;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    int j = 0;

    my_memset(tmp, 0, my_strlen(str) + 1);
    va_start(argv, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            my_putstr(tmp);
            my_memset(tmp, 0, my_strlen(str) + 1);
            j = 0;
            i++;
            tableau(str[i], argv);
        } else {
            tmp[j] = str[i];
            j++;
        }
    }
    my_putstr(tmp);
}