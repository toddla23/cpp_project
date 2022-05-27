#include <ncursesw/curses.h>
#include <locale.h>
#include <iostream>
#include <ctime>
#include <unistd.h>

#include "Snake.h"
#include "Growth.h"
#include "Poison.h"

int main()
{
    Snake s;
    s.init();

    Growth G;
    G.init();

    Poison P;
    P.init();

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



    int mv_cnt = 0;
    while(!s.SnakeIsDead())
    {
        
        char ch = getchar();
        for(int i = 0; i < s.getSize()+1; i++)
            mvwprintw(snake_win, s.getBody_X(i), s.getBody_Y(i), " ");

        s.move(ch);

        for(int i = 0; i < s.getSize(); i++)
            mvwprintw(snake_win, s.getBody_X(i), s.getBody_Y(i), "0");
        if(mv_cnt == 10)
        {

            mvwprintw(snake_win, G.getX(), G.getY(), " ");
            G.set(s);
            mvwprintw(snake_win, G.getX(), G.getY(), "G");


            mvwprintw(snake_win, P.getX(), P.getY(), " ");
            P.set(s);
            mvwprintw(snake_win, P.getX(), P.getY(), "P");

            mv_cnt = 0;
        }

        s.iseatG(G);
        s.iseatP(P);

        
        wrefresh(snake_win);

        mv_cnt++;
    }
    delwin(snake_win);
    
    mvprintw(11,40,"Game Over!!");
    getch();
    endwin();

    return 0;
}