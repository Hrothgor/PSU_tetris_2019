/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

tetri_t top_tetri(tetri_t tetri)
{
    tetri_t ret;

    ret = tetri;
    return (ret);
}

tetri_t right_tetri(tetri_t tetri)
{
    tetri_t ret;
    int i = 0;
    int j = 0;

    ret.c = tetri.c;
    ret.w = tetri.h;
    ret.h = tetri.w;
    if (tetri.data == NULL)
        return (ret);
    ret.data = malloc(sizeof(char *) * ret.h);
    for (int i = 0; i < ret.h; i++)
        ret.data[i] = malloc(sizeof(char) * ret.w);
    ret.name = tetri.name;
    for (int x = 0; x < tetri.w; x++) {
        for (int y = tetri.h; y > 0; y--) {
            ret.data[i][j] = tetri.data[y-1][x];
            j += 1;
        }
        i += 1;
        j = 0;
    }
    return (ret);
}

tetri_t bot_tetri(tetri_t tetri)
{
    tetri_t ret;
    int i = 0;
    int j = 0;

    ret.c = tetri.c;
    ret.w = tetri.w;
    ret.h = tetri.h;
    if (tetri.data == NULL)
        return (ret);
    ret.data = malloc(sizeof(char *) * ret.h);
    for (int i = 0; i < ret.h; i++)
        ret.data[i] = malloc(sizeof(char) * ret.w);
    ret.name = tetri.name;
    for (int y = tetri.h; y > 0; y--) {
        for (int x = tetri.w; x > 0; x--) {
            ret.data[i][j] = tetri.data[y-1][x-1];
            j += 1;
        }
        i += 1;
        j = 0;
    }
    return (ret);
}

tetri_t left_tetri(tetri_t tetri)
{
    tetri_t ret;
    int i = 0;
    int j = 0;

    ret.c = tetri.c;
    ret.w = tetri.h;
    ret.h = tetri.w;
    if (tetri.data == NULL)
        return (ret);
    ret.data = malloc(sizeof(char *) * ret.h);
    for (int i = 0; i < ret.h; i++)
        ret.data[i] = malloc(sizeof(char) * ret.w);
    ret.name = tetri.name;
    for (int x = tetri.w; x > 0; x--) {
        for (int y = 0; y < tetri.h; y++) {
            ret.data[i][j] = tetri.data[y][x-1];
            j += 1;
        }
        i += 1;
        j = 0;
    }
    return (ret);
}

tetri_t **get_all_tetri(tetri_t *list, int nb)
{
    tetri_t **ret = malloc(sizeof(tetri_t *) * nb);

    for (int i = 0; i < nb; i++)
        ret[i] = malloc(sizeof(tetri_t) * 4);
    for (int i = 0; i < nb; i++) {
        ret[i][0] = top_tetri(list[i]);
        ret[i][1] = right_tetri(list[i]);
        ret[i][2] = bot_tetri(list[i]);
        ret[i][3] = left_tetri(list[i]);
    }
    return (ret);
}