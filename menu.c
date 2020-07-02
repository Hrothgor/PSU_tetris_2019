/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/my.h"

char **get_ascii(void)
{
    char **ascii = malloc(sizeof(char *) * 7);
    ascii[6] = NULL;
    for (int i = 0; i < 5; i += 1) {
        ascii[i] = malloc(sizeof(char) * 45);
    }
    ascii[0] = " _______ ______ _______ _____  _____  _____ ";
    ascii[1] = "|__   __|  ____|__   __|  __ \\|_   _|/ ____|";
    ascii[2] = "   | |  | |__     | |  | |__) | | | | (___  ";
    ascii[3] = "   | |  |  __|    | |  |  _  /  | |  \\___ \\ ";
    ascii[4] = "   | |  | |____   | |  | | \\ \\ _| |_ ____) |";
    ascii[5] = "   |_|  |______|  |_|  |_|  \\_|_____|_____/ ";
    return (ascii);
}

menu_t init_menu(int width, int height, int start)
{
    menu_t menu;
    menu.options = malloc(sizeof(char *) * 4);
    menu.options[3] = NULL;
    for (int i = 0; i < 2; i += 1) {
        menu.options[i] = malloc(sizeof(char) * 5);
    }
    menu.options[0] = "PLAY";
    menu.options[1] = "HELP";
    menu.options[2] = "QUIT";
    menu.ascii_art = get_ascii();
    menu.height = height;
    menu.width = width;
    menu.start_x = 20;
    menu.start_y = start;

    return (menu);
}

void put_help(global_t *g)
{
    int key = 0;
    WINDOW *helpwin = newwin(15, 85, 0, 20);
    refresh();
    box(helpwin, 0, 0);
    while ((key = any_key()) == 0) {
    mvwprintw(helpwin, 1, 1, "Usage: ./tetris [options]");
    mvwprintw(helpwin, 2, 1, "Options:");
    mvwprintw(helpwin, 3, 1, "--help               Display this help");
    mvwprintw(helpwin, 4, 1, "-l --key-left={K}    Move the tetrimino LEFT using the K key (def: left arrow)");
    mvwprintw(helpwin, 5, 1, "-r --key-right={K}   Move the tetrimino RIGHT using the K key (def: right arrow)");
    mvwprintw(helpwin, 6, 1, "-r --key-right={K}   Move the tetrimino RIGHT using the K key (def: right arrow)");
    mvwprintw(helpwin, 7, 1, "-d --key-drop={K}    DROP the tetrimino using the K key (def: down arrow)");
    mvwprintw(helpwin, 8, 1, "-q --key-quit={K}    QUIT the game using the K key (def: 'q' key)");
    mvwprintw(helpwin, 9, 1, "-p --key-pause={K}   PAUSE/RESTART the game using the K key (def: space bar)");
    mvwprintw(helpwin, 10, 1, "--map-size={row,col} Set the numbers of rows and columns of the map (def: 20,10)");
    mvwprintw(helpwin, 11, 1, "-w --without-next    Hide next tetrimino (def: false)");
    mvwprintw(helpwin, 12, 1, "-D --debug           Debug mode (def: false)");
    mvwprintw(helpwin, 13, 1, "Press any key to go back to menu!");
    wrefresh(helpwin);
    }
    wclear(helpwin);
    wrefresh(helpwin);
    g->state = 1;
}

void put_menu(menu_t menu, menu_t title, global_t *g)
{
    int choice;
    int highlight = 0;
    char **arr = my_str_to_word_array_char(read_map("draw.txt"), '\n');
    WINDOW *dessin = newwin(20, 50, 20, 20);
    WINDOW *menuwin = newwin(menu.height, menu.width, menu.start_y, menu.start_x);
    WINDOW *titlewin = newwin(title.height, title.width, title.start_y, title.start_x);
    keypad(menuwin, true);

    refresh();
    box(menuwin, 0, 0);
    box(titlewin, 0, 0);
    while (1) {
        werase(dessin);
        for (int i = 0; arr[i]; i++) {
            for (int j = 0; arr[i][j]; j++) {
                if (arr[i][j] != ' ') {
                    wattron(dessin, COLOR_PAIR(arr[i][j] - '0'));
                    mvwprintw(dessin ,i, j, "%c", arr[i][j]);
                    wattroff(dessin, COLOR_PAIR(arr[i][j] - '0'));
                }
            }
        }
        wrefresh(dessin);
        for (int i = 0; i < 3; i += 1) {
            if (i == highlight)
                wattr_on(menuwin, A_REVERSE, NULL);
            mvwprintw(menuwin, i + 1, 1, menu.options[i]);
            wattroff(menuwin, A_REVERSE);
        }
        wrefresh(menuwin);
        for(int i = 0; i < 6; i += 1) {
            mvwprintw(titlewin, i + 1, 1, title.ascii_art[i]);
        }
        wrefresh(titlewin);
        choice = wgetch(menuwin);
        switch(choice) {
            case KEY_UP:
                highlight -= 1;
                if (highlight == - 1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight += 1;
                if (highlight == 3)
                    highlight = 2;
                break;
            default:
                break;
            }
        if (choice == 10 && menu.options[highlight][0] == 'P') {
            g->state = 2;
            wclear(menuwin);
            wrefresh(menuwin);
            wclear(titlewin);
            wrefresh(titlewin);
            wclear(dessin);
            wrefresh(dessin);
            break;
        } else if (choice == 10 && menu.options[highlight][0] == 'Q') {
            g->state = 0;
            break;
        } else if (choice == 10 && menu.options[highlight][0] == 'H') {
            put_help(g);
            break;
        }
    }
}
