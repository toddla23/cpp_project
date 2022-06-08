#include <ncursesw/curses.h>
#include <locale.h>
#include <iostream>
#include <time.h>
#include <unistd.h>

#include "Snake.h"
#include "Growth.h"
#include "Poison.h"
#include "Wall.h"
#include "Gate.h"

#include <sys/select.h>
#include <unistd.h>
#include <termios.h>

static struct termios initial_settings, new_settings;
static int peek_character = -1;
void init_keyboard()
{	
    tcgetattr(0,&initial_settings);
	new_settings = initial_settings;	
    new_settings.c_lflag &= ~ICANON;	
    new_settings.c_lflag &= ~ECHO;	
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;	tcsetattr(0, TCSANOW, &new_settings);
}
   
void close_keyboard()
{	
    tcsetattr(0, TCSANOW, &initial_settings);
}

int _kbhit()
{
    unsigned char ch;
    int nread;

    if (peek_character != -1) 
        return 1;    	
    
    new_settings.c_cc[VMIN]=0;
        
    tcsetattr(0, TCSANOW, &new_settings);
        
    nread = read(0,&ch,1);	
    new_settings.c_cc[VMIN]=1;
        
    tcsetattr(0, TCSANOW, &new_settings);	

    if(nread == 1)
    {		
        peek_character = ch;		
        return 1;	
    }	
    return 0;
}
    
int _getch()
{
	char ch;	
    if(peek_character != -1)
	{		
        ch = peek_character;		
        peek_character = -1;		
        return ch;	
    }	
    
    read(0,&ch,1);
    return ch;
}

int _putch(int c)
{
	putchar(c);
	fflush(stdout);
	return c;
}

int main()
{
    Snake s;
    Growth G;
    Poison P;

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
    mvprintw(1, 35, "SNAKE GAME!");

    mvprintw(10, 35, "Choose stage 1~4!");

    int stage;

    Wall w(1);
    Gate gate;
    refresh();


    mvprintw(10, 35, "                         ");
    refresh();


    snake_win = newwin(mapsize,mapsize,2,2); 
    wborder(snake_win, 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M');

    for(int i = 0; i < s.getSize(); i++)
    {
        mvwprintw(snake_win, s.getBody_X(i), s.getBody_Y(i), "0");
    }

    wrefresh(snake_win);

    clock_t start, finish;
    double duration;

    start = clock(); 

    int ch = 97;
    int mv_cnt = 0;


        mvwprintw(snake_win, gate.getX1(), gate.getY1(), "M");
        mvwprintw(snake_win, gate.getX2(), gate.getY2(), "M");
        gate.set(w);
        
    while(!s.SnakeIsDead(gate) && ch != 'l')
    {
        
        finish  = clock(); 
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        
        if(_kbhit())
        {
            ch = _getch();
            _putch(ch);
        }    
        
        for(int i = 0; i < s.getSize()+1; i++)
            mvwprintw(snake_win, s.getBody_X(i), s.getBody_Y(i), " ");
        

        if(duration >= 0.3)
        {
            s.move(ch);
            mv_cnt++;
            
        if(mv_cnt % 10 == 0)
        {
            mvwprintw(snake_win, G.getX(), G.getY(), " ");
            G.set(s);
            mvwprintw(snake_win, G.getX(), G.getY(), "G");


            mvwprintw(snake_win, P.getX(), P.getY(), " ");
            P.set(s);
            mvwprintw(snake_win, P.getX(), P.getY(), "P");
        }

       /* if(mv_cnt % 10 == 0)
        {
            mvwprintw(snake_win, gate.getX1(), gate.getY1(), "M");
            mvwprintw(snake_win, gate.getX2(), gate.getY2(), "M");

            gate.set(w);
            mvwprintw(snake_win, gate.getX1(), gate.getY1(), "D");
            mvwprintw(snake_win, gate.getX2(), gate.getY2(), "D");

        }*/
            s.iseatG(G);
            s.iseatP(P);
            start = clock();
        }

        
        for(int i = 0; i < s.getSize(); i++)
            mvwprintw(snake_win, s.getBody_X(i), s.getBody_Y(i), "0");
        s.is_enter_gate(gate);

        
        wrefresh(snake_win);
        mvprintw(5, 60, "time : %d seconds ", mv_cnt/2);
        mvprintw(6, 60, "score : %d !!!! ", s.getSize());
        mvprintw(10, 60, "input : ");

        mvwprintw(snake_win, gate.getX1(), gate.getY1(), "D");
        mvwprintw(snake_win, gate.getX2(), gate.getY2(), "D");
   
        refresh();
    }
    delwin(snake_win);
    
    mvprintw(11,40,"Game Over!!");
    getch();
    endwin();

    return 0;
}