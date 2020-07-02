/*
** EPITECH PROJECT, 2019
** my
** File description:
** My Header
*/

#include "include.h"

typedef struct info {
    int help;
    int level;
    char *key_left;
    char *key_right;
    char *key_turn;
    char *key_drop;
    char *key_quit;
    char *key_pause;
    int map_row;
    int map_col;
    int without_next;
    int debug;
} info_t;

typedef struct t_data {
    struct dirent *p_dirent;
    struct stat stats;
    DIR *p_dir;
    char *tmp;
    char *time;
} s_data;

typedef struct opt_short {
    char c;
    void (*func) (info_t *);
} opt_short_t;

typedef struct tetriminos {
    char *name;
    int w;
    int h;
    int c;
    char **data;
} tetri_t;

typedef struct entity {
    tetri_t tetris;
    int x;
    int y;
    int init;
    int rota;
    int who;
} entity_t;

typedef struct menu {
    char **ascii_art;
    char **options;
    int width;
    int height;
    int start_x;
    int start_y;
} menu_t;

typedef struct global {
    tetri_t **all_tetri;
    int nb_tetri;
    char **map;
    int state;
    int score;
    int line;
    WINDOW *game;
    WINDOW *next;
    WINDOW *status;
    entity_t next_tetri;
    info_t info;
    clock_t clock1;
    clock_t clock2;
} global_t;