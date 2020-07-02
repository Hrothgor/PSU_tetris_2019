/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

const opt_short_t opt_short[] = {
    {1, &opt_help},
    {'L', &opt_level},
    {'l', &opt_key_left},
    {'r', &opt_key_right},
    {'t', &opt_key_turn},
    {'d', &opt_key_drop},
    {'q', &opt_key_quit},
    {'p', &opt_key_pause},
    {2, &opt_map_size},
    {'w', &opt_without_next},
    {'D', &opt_debug},
    {0, NULL}
};

const struct option opt_long[] = {
    {"help", 0, 0, 1},
    {"level", 1, 0, 'L'},
    {"key-left", 1, 0, 'l'},
    {"key-right", 1, 0, 'r'},
    {"key-turn", 1, 0, 't'},
    {"key-drop", 1, 0, 'd'},
    {"key-quit", 1, 0, 'q'},
    {"key-pause", 1, 0, 'p'},
    {"map-size", 2, 0, 2},
    {"without-next", 0, 0, 'w'},
    {"debug", 0, 0, 'D'},
    {0, 0, 0, 0}
};

char *key(char *c)
{
    if (c[0] == ' ')
        return ("(space)");
    if (c[0] == '3')
        return ("^EOA");
    if (c[0] == '4')
        return ("^EOB");
    if (c[0] == '5')
        return ("^EOC");
    if (c[0] == '6')
        return ("^EOD");
    return (c);
}

void print_debug(info_t info, tetri_t *list, char **av)
{
    my_printf("*** DEBUG MODE ***\n");
    my_printf("Key Left : %s\n", key(info.key_left));
    my_printf("Key Right : %s\n", key(info.key_right));
    my_printf("Key Turn : %s\n", key(info.key_turn));
    my_printf("Key Drop : %s\n", key(info.key_drop));
    my_printf("Key Quit : %s\n", key(info.key_quit));
    my_printf("Key Pause : %s\n", key(info.key_pause));
    if (!info.without_next)
        my_printf("Next : Yes\n");
    else
        my_printf("Next : No\n");
    my_printf("Level : %i\n", info.level);
    my_printf("Size : %i*%i\n", info.map_row, info.map_col);
    my_printf("Tetriminos : %i\n", get_total("tetriminos", av));
    for (int i = 0; list[i].name; i++)
        print_tetri_info(list[i]);
    my_printf("Press any key to start Tetris\n");
}

void fill_info(int ac, char **av, info_t *info)
{
    int opt;
    int check = 0;
    int opt_index = 0;

    while ((opt = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", opt_long, &opt_index)) != -1) {
        check = 0;
        for (int i = 0; opt_short[i].c; i++) {
            if (opt == opt_short[i].c) {
                check = 1;
                opt_short[i].func(info);
                continue;
            }
        }
        if (!check) {
            print_help(av);
            exit(84);
        }
    }
}
