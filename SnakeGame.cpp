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
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    resize_term(25,80);
    start_color();

    border('|', '|', '-', '-', '+', '+', '+', '+');
    mvprintw(1, 15, "SNAKE GAME!");
    refresh();

    snake_win = newwin(mapsize,mapsize,2,2); 
    wborder(snake_win, '|', '|', '-', '-', '+', '+', '+', '+');

    for(int i = 0; i < s.getSize(); i++)
    {
        mvwprintw(snake_win, s.getBody_X(i), s.getBody_Y(i), "0");
    }

    wrefresh(snake_win);

    while(!s.SnakeIsDead())
    {
        
        char ch = getch();
        for(int i = 0; i < s.getSize(); i++)
            mvwprintw(snake_win, s.getBody_X(i), s.getBody_Y(i), " ");

        s.move(ch);

        for(int i = 0; i < s.getSize(); i++)
            mvwprintw(snake_win, s.getBody_X(i), s.getBody_Y(i), "0");

        wrefresh(snake_win);

    }

    getch();

    delwin(snake_win);
    endwin();

    return 0;
}