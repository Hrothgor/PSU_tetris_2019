/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

void update_input(global_t *g, entity_t *entity, int key)
{
    if (key == KEY_LEFT)
        if (entity->x > 0) {
            entity->x -= 1;
            if (check_collision(g, entity) == 1)
                entity->x += 1;
        }
    if (key == KEY_RIGHT)
        if (entity->x < g->info.map_row-entity->tetris.w) {
            entity->x += 1;
            if (check_collision(g, entity) == 1)
                entity->x -= 1;
        }
    if (key == 'b') {
        entity->y += 1;
        if (check_collision(g, entity) == 1) {
            entity->y -= 1;
            cat_tetri_on_map(g, entity);
        }
    }
    if (key == 'a') {
        entity->rota += 1;
        if (entity->rota == 4)
            entity->rota = 0;
        entity->tetris = g->all_tetri[entity->who][entity->rota];
        if (entity->x + entity->tetris.w > g->info.map_row || check_collision(g, entity) == 1) {
            entity->rota -= 1;
            if (entity->rota == -1)
                entity->rota = 3;
            entity->tetris = g->all_tetri[entity->who][entity->rota];
        }
    }
    if (key == 27) {
        g->state = 1;
        werase(g->game);
        wrefresh(g->game);
        werase(g->next);
        wrefresh(g->next);
        werase(g->status);
        wrefresh(g->status);
    }
}

int init_entity(global_t *g, entity_t *entity)
{
    static int i = 0;

    if (i == 0) {
        g->next_tetri.who = rand() % g->nb_tetri;
        g->next_tetri.x = g->info.map_row/2;
        g->next_tetri.y = 0;
        g->next_tetri.tetris = g->all_tetri[g->next_tetri.who][0];
        g->next_tetri.init = 1;
        g->next_tetri.rota = 0;
    }
    *entity = g->next_tetri;
    g->next_tetri.who = rand() % g->nb_tetri;
    g->next_tetri.x = g->info.map_row/2;
    g->next_tetri.y = 0;
    g->next_tetri.tetris = g->all_tetri[g->next_tetri.who][0];
    g->next_tetri.init = 1;
    g->next_tetri.rota = 0;
    if (check_collision(g, entity) == 1) {
        g->state = 0;
        return (84);
    }
    i++;
    return (0);
}

int update_entity(global_t *g)
{
    static entity_t entity;
    int key = 0;

    if (entity.init == 0)
        if (init_entity(g, &entity) == 84)
            return (0);
    g->clock1 = clock();
    while ((double) (g->clock2) - (double) (g->clock1) < (double) 1000000/(1+((double) g->info.level/10))) {
        key = getch();
        update_input(g, &entity, key);
        if (g->state != 2)
            return (84);
        if (entity.init == 0)
            return (0);
        werase(g->game);
        box(g->game, 0, 0);
        mvwprintw(g->game, 0, 2, "TETRIS");
        draw_map(g);
        draw_tetri_on_map(g, entity);
        wrefresh(g->game);
        g->clock2 = clock();
    }
    entity.y += 1;
    if (check_collision(g, &entity) == 1) {
        entity.y -= 1;
        cat_tetri_on_map(g, &entity);
    }
    return (0);
}

void init_game(global_t *g)
{
    initscr();
    start_color();
    init_pair(8, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    g->state = 1;
    g->score = 0;
    g->line = 0;
    g->game = newwin(g->info.map_col+2, g->info.map_row+2, 2, 50);
    g->next = newwin(7, 13, g->info.map_col/2, 55+g->info.map_row);
    g->status = newwin(9, 20, 2, 30);
    box(g->game, 0, 0);
    box(g->next, 0, 0);
    box(g->status, 0, 0);
}

void start_ncurses(global_t *g)
{
    menu_t menu = init_menu(47, 5, 10);
    menu_t title = init_menu(47, 9, 1);
    int i = 0;

    init_game(g);
    while (LINES < g->info.map_row+30 || COLS < g->info.map_col+15) {
        erase();
        printw("ENLARGE TERMINAL PLEASE");
        refresh();
    }
    erase();
    while (g->state != 0) {
        if (g->state == 1)
            put_menu(menu, title, g);
        if (g->state == 2) {
            i = game_box(g);
            if (i != 84) {
                if (g->info.without_next == 0)
                    next_box(g);
                info_box(g);
            }
        }
    }
    endwin();
    printf("You lost whith %i points and level %i", g->score, g->info.level);
}