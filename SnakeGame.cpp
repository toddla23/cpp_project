#include <ncursesw/curses.h>
#include <locale.h>
#include <iostream>

int main()
{

    setlocale(LC_ALL, "");

    WINDOW * snake_win;
    initscr();
    resize_term(25,60);
    start_color();

    border('|', '|', '-', '-', '+', '+', '+', '+');
    mvprintw(1, 6, "SNAKE GAME!");
    refresh();

    snake_win = newwin(20,34,2,2);    
    for(int i = 0; i < 18; i++)
        for(int j = 1; j < 17; j++)
            mvwprintw(snake_win, i, j, "\u2B1c");
    wrefresh(snake_win); 


    getch();
    delwin(snake_win);
    endwin();

    return 0;
}