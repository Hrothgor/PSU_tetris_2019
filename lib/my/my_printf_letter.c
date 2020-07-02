/*
** EPITECH PROJECT, 2019
** my_printf_letter.c
** File description:
** my_printf_letter
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../../include/my.h"

void print_str(va_list argv)
{
    my_putstr(va_arg(argv, char *));
}

void print_car(va_list argv)
{
    my_putchar(va_arg(argv, int));
}