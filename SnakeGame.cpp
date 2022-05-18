#include <ncursesw/curses.h>
#include <locale.h>
#include <iostream>

int main()
{

    setlocale(LC_ALL, "");

    int mapsize = 21;

    WINDOW * snake_win;
    initscr();
    resize_term(25,40);
    start_color();

    border('|', '|', '-', '-', '+', '+', '+', '+');
    mvprintw(1, 6, "SNAKE GAME!");
    refresh();

    snake_win = newwin(mapsize,mapsize,2,2); 
    wborder(snake_win, '1', '1', '1', '1', '2', '2', '2', '2');   
    for(int i = 1; i < mapsize-1; i++)
        for(int j = 1; j < mapsize-1; j++)
            mvwprintw(snake_win, i, j, "0");
    wrefresh(snake_win); 


    getch();
    delwin(snake_win);
    endwin();

    return 0;
}
