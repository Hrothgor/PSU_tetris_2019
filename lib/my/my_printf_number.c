/*
** EPITECH PROJECT, 2019
** my_printf_number.c
** File description:
** my_printf_number
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../../include/my.h"

void print_int(va_list argv)
{
    my_put_nbr(va_arg(argv, int));
}

void print_unsigned_int(va_list argv)
{
    my_put_nbr_unsigned(va_arg(argv, long int));
}

void print_modulo(va_list argv)
{
    my_putchar('%');
}