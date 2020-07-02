/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

char *get_name(char *filepath)
{
    int index = get_last_point(filepath);
    char *name = my_strncpy(filepath, index);
    char **map2 = my_str_to_word_array_char(name, '/');

    return (map2[2]);
}


tetri_t init_tetri(char **map, char *filepath)
{
    char **line1 = my_str_to_word_array_char(map[0], ' ');
    tetri_t tetrimino;

    tetrimino.name = get_name(filepath);
    tetrimino.w = my_atoi(line1[0]);
    tetrimino.h = my_atoi(line1[1]);
    tetrimino.c = my_atoi(line1[2]);
    tetrimino.data = ++map;
    for (int i = 0; i < tetrimino.h; i++)
        for (int j = 0; j < tetrimino.w; j++)
            if (tetrimino.data[i][j] == ',')
                tetrimino.data[i][j] = ' ';
    free(line1);
    return (tetrimino);
}

tetri_t tetris_info(char *filepath)
{
    char *buffer = read_map(filepath);
    char **map = my_str_to_word_array_char(buffer, '\n');
    tetri_t tetrimino;

    if (check_tetri_error(map) == -1)
        tetrimino = error_tetri(filepath);
    else
        tetrimino = init_tetri(map, filepath);
    return (tetrimino);
}

int get_total(char *str, char **av)
{
    s_data data;
    char *path = my_strcat("./", str);
    int total = 0;

    data.p_dir = opendir(path);
    if (ENOTDIR != errno && (data.p_dir == NULL)) {
        my_printf("Directory cannot be read\n");
        print_help(av);
        exit (84);
    } else {
        while ((data.p_dirent = readdir(data.p_dir)) != NULL) {
            if (data.p_dirent->d_name[0] != '.') {
                total += 1;
            }
        }
    }
    if (total == 0) {
        print_help(av);
        exit(84);
    }
    closedir(data.p_dir);
    return (total);
}

tetri_t *print_list_l(char *str, char **av)
{
    s_data data;
    int index = 0;
    char *r_p;
    char *path = my_strcat("./", str);
    tetri_t *list = malloc(sizeof(tetri_t) * ((get_total(str, av)) + 1));

    list[get_total(str, av)].name = NULL;
    data.p_dir = opendir(path);
    if (ENOTDIR != errno && (data.p_dir == NULL)) {
        my_printf("Directory cannot be read\n");
        print_help(av);
        exit (84);
    } else {
        while ((data.p_dirent = readdir(data.p_dir)) != NULL) {
            if (my_strlen(data.p_dirent->d_name) > 2) {
                r_p = my_strcat(my_strcat(path, "/"), data.p_dirent->d_name);
                list[index++] = tetris_info(r_p);
            }
        }
    }
    closedir(data.p_dir);
    return (sorted(list, str, av));
}