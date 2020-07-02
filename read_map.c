/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

char *read_map(char *path)
{
    struct stat sd;
    char *buffer;
    int fd;

    if (stat(path, &sd) == -1)
        exit(84);
    buffer = malloc(sizeof(char) * (sd.st_size + 1));
    my_memset(buffer, 0, sd.st_size + 1);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    read(fd, buffer, sd.st_size + 1);
    close(fd);
    return (buffer);
}

tetri_t error_tetri(char *filepath)
{
    tetri_t tetri;

    tetri.name = get_name(filepath);
    tetri.w = -1;
    tetri.h = -1;
    tetri.c = -1;
    tetri.data = NULL;
    return (tetri);
}

void print_tetri_info(tetri_t tetri)
{
    int i = 0;

    if (tetri.w == -1)
        my_printf("Tetriminos : Name %s : Error\n", tetri.name);
    else {
        my_printf("Tetriminos : Name %s : ", tetri.name);
        my_printf("Size %i*%i : Color %i :\n", tetri.h, tetri.w, tetri.c);
        while(tetri.data[i]) {
            my_printf("%s\n", tetri.data[i]);
            i += 1;
        }
    }
}

tetri_t *sorted(tetri_t *list, char *str, char **av)
{
    int len = get_total(str, av);
    tetri_t tmp;

    for (int i = 0; i < len+1; i++) {
        for (int j = 0; j < len-1; j++) {
            if (my_strcmp(list[j].name, list[j+1].name) == 1) {
                tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
    }
    return (list);
}