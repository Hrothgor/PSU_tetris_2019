/*
** EPITECH PROJECT, 2019
** my
** File description:
** My Header
*/

#include "include.h"
#include "struct.h"

void my_printf(char *, ...);
void print_int(va_list);
void print_unsigned_int(va_list);
void print_modulo(va_list);
void print_str(va_list);
void print_car(va_list);
void my_putchar(char);
int my_putstr(char const *);
int my_put_nbr(int);
int my_put_nbr_unsigned(long int);
int my_atoi(char const *);
char *my_itostr(int);
void my_memset(char *, int, int);
int my_strlen(char const *);
char **my_str_to_word_array_char(char *, char);
char **my_str_to_word_array(char *);
int my_strcmp(char const *, char const *);
char *my_strdup(char const *);
char *my_strcat(char *, char const *);

/////// INFO ////////

info_t init_info(void);
void print_debug(info_t, tetri_t *, char **av);
void fill_info(int, char **, info_t *);

//////// Tetriminos ///////

char *read_map(char *);
char **get_2d_map(char *);
char *get_name(char *);
int get_total(char *, char **av);
tetri_t init_tetri(char **map, char *filepath);
tetri_t tetris_info(char *filepath);
tetri_t *print_list_l(char *str, char **av);
tetri_t print_error(char **map, char *filepath);
tetri_t *alloc_list(int total);
tetri_t error_tetri(char *filepath);
void print_tetri_info(tetri_t tetri);
tetri_t *sorted(tetri_t *l_tetri, char *str, char **av);
int check_map(char **map);
int check_tetri_error(char **map);
int get_last_point(char *filepath);
char *my_strncpy(char *filepath, int index);
tetri_t **get_all_tetri(tetri_t *list, int nb);

//////// Func ////////

void opt_help(info_t *info);
void opt_level(info_t *info);
void opt_key_left(info_t *info);
void opt_key_right(info_t *info);
void opt_key_turn(info_t *info);
void opt_key_drop(info_t *info);
void opt_key_quit(info_t *info);
void opt_key_pause(info_t *info);
void opt_map_size(info_t *info);
void opt_without_next(info_t *info);
void opt_debug(info_t *info);

//////// HELP ////////

void print_help(char **av);

//////// NCURSES ////////

void start_ncurses(global_t *g);
int any_key(void);
int check_collision(global_t *g, entity_t *entity);
void draw_map(global_t *g);
void draw_tetri_on_map(global_t *g, entity_t entity);
void cat_tetri_on_map(global_t *g, entity_t *entity);
void check_line(global_t *g);
int game_box(global_t *g);
void next_box(global_t *g);
void info_box(global_t *g);
int update_entity(global_t *g);
int init_entity(global_t *g, entity_t *entity);
void update_input(global_t *g, entity_t *entity, int key);
void put_menu(menu_t menu, menu_t title, global_t *g);
menu_t init_menu(int width, int height, int start) ;