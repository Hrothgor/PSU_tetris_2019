/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

info_t init_info(void)
{
    info_t ret;

    ret.help = 0;
    ret.level = 1;
    ret.key_left = "6";
    ret.key_right = "5";
    ret.key_turn = "a";
    ret.key_drop = "b";
    ret.key_quit = "q";
    ret.key_pause = " ";
    ret.map_row = 20;
    ret.map_col = 10;
    ret.without_next = 0;
    ret.debug = 0;
    return (ret);
}

void print_help(char **av)
{
    my_printf("Usage: %s [options]\n", av[0]);
    my_printf("Options:\n");
    my_printf(" --help               Display this help\n");
    my_printf(" -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_printf(" -l --key-left={K}    Move the tetrimino LEFT using \
the K key (def: left arrow)\n");
    my_printf(" -r --key-right={K}   Move the tetrimino RIGHT using \
the K key (def: right arrow)\n");
    my_printf(" -t --key-turn={K}    TURN the tetrimino clockwise 90d \
using the K key (def: top arrow)\n");
    my_printf(" -d --key-drop={K}    DROP the tetrimino using the K key \
(def: down arrow)\n");
    my_printf(" -q --key-quit={K}    QUIT the game using the K key \
(def: 'q' key)\n");
    my_printf(" -p --key-pause={K}   PAUSE/RESTART the game using \
the K key (def: space bar)\n");
    my_printf(" --map-size={row,col} Set the numbers of rows and columns \
of the map (def: 20,10)\n");
    my_printf(" -w --without-next    Hide next tetrimino (def: false)\n");
    my_printf(" -D --debug           Debug mode (def: false)\n");
}

int any_key(void)
{
    struct termios oldt;
    struct termios newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF) {
        ungetc(ch, stdin);
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    global_t *g = malloc(sizeof(global_t));
    tetri_t *list = print_list_l("tetriminos", av);
    int key = 0;

    srand(time(NULL));
    g->info = init_info();
    g->nb_tetri = get_total("tetriminos", av);
    g->all_tetri = get_all_tetri(list, g->nb_tetri);
    fill_info(ac, av, &g->info);
    if (g->info.help) {
        print_help(av);
        return (0);
    }
    if (g->info.debug) {
        print_debug(g->info, list, av);
        while ((key = any_key()) == 0);
    }
    g->map = malloc(sizeof(char *) * (g->info.map_col + 1));
    g->map[g->info.map_col] = NULL;
    for (int i = 0; i < g->info.map_col; i++) {
        g->map[i] = malloc(sizeof(char) * g->info.map_row + 1);
        my_memset(g->map[i], 32, g->info.map_row + 1);
    }
    start_ncurses(g);
    return (0);
}
