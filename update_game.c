/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

void check_line(global_t *g)
{
    int check = 0;
    int point = 0;
    static int up = 0;

    for (int y = 0; y < g->info.map_col; y++) {
        check = 1;
        for (int x = 0; x < g->info.map_row; x++) {
            if (g->map[y][x] != '*')
                check = 0;
        }
        if (check == 1) {
            up += 1;
            g->score += 1 + point;
            g->line += 1;
            point += 1;
            for (int i = y; i > 0; i--)
                g->map[i] = g->map[i-1];
            for (int x = 0; x < g->info.map_row; x++)
                g->map[0][x] = ' ';
        }
    }
    if (up == 10) {
        up = 0;
        g->info.level += 1;
    }
}

void info_box(global_t *g)
{
    werase(g->status);
    box(g->status, 0, 0);
    mvwprintw(g->status, 0, 2, "STATUS");
    mvwprintw(g->status, 2, 1, "Level :\t%i", g->info.level);
    mvwprintw(g->status, 4, 1, "Score :\t%i", g->score);
    mvwprintw(g->status, 5, 1, "Lines :\t%i", g->score);
    mvwprintw(g->status, 7, 1, "Timer :\t%i", (int) g->clock1/CLOCKS_PER_SEC);
    wrefresh(g->status);
}


int game_box(global_t *g)
{
    int i = 0;

    werase(g->game);
    box(g->game, 0, 0);
    i = update_entity(g);
    if (i == 84)
        return (i);
    check_line(g);
    draw_map(g);
    wrefresh(g->game);
    return (0);
}

void next_box(global_t *g)
{
    werase(g->next);
    box(g->next, 0, 0);
    mvwprintw(g->next, 0, 2, "NEXT");
    for (int i = 0; g->next_tetri.tetris.data[i]; i++)
        mvwprintw(g->next, 2+i, 5, "%s", g->next_tetri.tetris.data[i]);
    wrefresh(g->next);
}