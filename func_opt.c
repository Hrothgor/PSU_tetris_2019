/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

void opt_help(info_t *info)
{
    info->help = 1;
}

void opt_level(info_t *info)
{
    for (int i = 0; optarg[i]; i++)
        if (optarg[i] < '0' && optarg[i] > '9')
            exit(84);
    if (optarg[0] == '\0')
        exit(84);
    info->level = my_atoi(optarg);
}

void opt_key_left(info_t *info)
{
    if (optarg[0] == '\0')
        exit(84);
    info->key_left = optarg;
}

void opt_key_right(info_t *info)
{
    if (optarg[0] == '\0')
        exit(84);
    info->key_right = optarg;
}

void opt_key_turn(info_t *info)
{
    if (optarg[0] == '\0')
        exit(84);
    info->key_turn = optarg;
}

void opt_key_drop(info_t *info)
{
    if (optarg[0] == '\0')
        exit(84);
    info->key_drop = optarg;
}

void opt_key_quit(info_t *info)
{
    if (optarg[0] == '\0')
        exit(84);
    info->key_quit = optarg;
}

void opt_key_pause(info_t *info)
{
    if (optarg[0] == '\0')
        exit(84);
    info->key_pause = optarg;
}

void opt_map_size(info_t *info)
{
    static int i = 0;

    for (int i = 0; optarg[i]; i++)
        if (optarg[i] < '0' && optarg[i] > '9')
            exit(84);
    if (optarg[0] == '\0')
        exit(84);
    if (!i++)
        info->map_row = my_atoi(optarg);
    else
        info->map_col = my_atoi(optarg);
}

void opt_without_next(info_t *info)
{
    info->without_next = 1;
}

void opt_debug(info_t *info)
{
    info->debug = 1;
}
