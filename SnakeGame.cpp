#include <ncursesw/curses.h>
#include <locale.h>
#include <iostream>
#include "snake.h"

int main()
{
    Snake s;
    s.init();

    setlocale(LC_ALL, "");

    int mapsize = 21;

    WINDOW * snake_win;
    initscr();
    resize_term(25,80);
    start_color();

    border('|', '|', '-', '-', '+', '+', '+', '+');
    mvprintw(1, 15, "SNAKE GAME!");
    refresh();

    snake_win = newwin(mapsize,mapsize,2,2); 
    for(int i = 0; i < mapsize; i++)
        for(int j = 0; j < mapsize; j++)
            mvwprintw(snake_win, i, j, "\u2B1C");

    for(int i = 0; i < s.getSize(); i++)
    {
        mvwprintw(snake_win, s.getBody_X(i), s.getBody_Y(i), "\u2B1B");
    }
    wrefresh(snake_win); 


    getch();
    delwin(snake_win);
    endwin();

    return 0;
}