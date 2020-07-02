/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

int check_collision(global_t *g, entity_t *entity)
{
    if (entity->y + entity->tetris.h - 1 >= g->info.map_col)
        return (1);
    for (int y = 0; y < g->info.map_col; y++)
        for (int x = 0; x < g->info.map_row; x++)
            for (int i = 0; i < entity->tetris.h; i++)
                for (int j = 0; j < entity->tetris.w; j++)
                    if (entity->tetris.data[i][j] == '*' && g->map[y][x] == '*')
                        if (i + entity->y == y && j + entity->x == x)
                            return (1);
    return (0);
}

void cat_tetri_on_map(global_t *g, entity_t *entity)
{
    for (int y = 0; y < entity->tetris.h; y++)
        for (int x = 0; x < entity->tetris.w; x++)
            if (entity->tetris.data[y][x] == '*')
                g->map[entity->y + y][entity->x + x] = entity->tetris.data[y][x];
    entity->init = 0;
}

void draw_map(global_t *g)
{
    for (int i = 0; i < g->info.map_col; i++) {
        for (int j = 0; j < g->info.map_row; j++) {
            if (g->map[i][j] == '*') {
                wattron(g->game, COLOR_PAIR(1));
                mvwprintw(g->game, i+1, j+1,"%c", g->map[i][j]);
                wattroff(g->game, COLOR_PAIR(1));
            } else {
                mvwprintw(g->game, i+1, j+1,"%c", g->map[i][j]);
            }
        }
    }
}

void draw_tetri_on_map(global_t *g, entity_t entity)
{
    for (int i = 0; i < entity.tetris.h; i++)
        for (int j = 0; j < entity.tetris.w; j++)
            if (entity.tetris.data[i][j] == '*') {
                wattron(g->game, COLOR_PAIR(entity.tetris.c));
                mvwprintw(g->game, entity.y+1+i, entity.x+1+j, "%c", entity.tetris.data[i][j]);
                wattroff(g->game, COLOR_PAIR(entity.tetris.c));
            }
}