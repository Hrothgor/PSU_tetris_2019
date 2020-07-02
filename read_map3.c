/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

int check_map(char **map)
{
    for (int j = 1; map[j] != NULL; j += 1) {
        for (int i = 0; map[j][i+1] != '\0'; i += 1) {
            if (map[j][i] != '*' && map[j][i] != ' ') {
                return (-1);
            }
        }
    }
    return (0);
}

int check_star_numbers(char **map)
{
    char **line1 = my_str_to_word_array_char(map[0], ' ');
    int h = 0;
    int w = 0;
    int w_max = 0;

    for (int j = 1; map[j] != NULL; j += 1) {
        for (int i = 0; map[j][i] != '\0'; i += 1) {
            if (map[j][i] == '*' || map[j][i] == ' ')
                w += 1;
        }
        if (w > 0)
            h += 1;
        if (w > w_max)
            w_max = w;
        w = 0;
    }
    if (h != my_atoi(line1[1]) || w_max != my_atoi(line1[0]))
        return (-1);
    else
        return (0);
}

int check_tetri_error(char **map)
{
    if (map[1] == NULL)
        return (-1);
    if (check_map(map) == -1)
        return (-1);
    if (check_star_numbers(map) == -1)
        return (-1);
    return (0);
}

int get_last_point(char *filepath)
{
    int total = 0;
    int counter = 0;
    int index = 0;
    for (int i = 0; filepath[i] != '\0'; i += 1) {
        if (filepath[i] == '.')
            total += 1;
    }
    for (int i = 0; filepath[i] != '\0'; i += 1) {
        if (filepath[i] == '.')
            counter += 1;
        if (counter == total) {
            index = i;
            break;
        }
    }
    return (index);
}

char *my_strncpy(char *filepath, int index)
{
    char *name = malloc(sizeof(char) * index);
    name[index] = '\0';
    for (int i = 0; i < index; i += 1) {
        name[i] = filepath[i];
    }
    return (name);
}