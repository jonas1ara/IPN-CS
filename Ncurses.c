#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

//Función principal

int main(void)
{
    initscr();

    addstr("-----------------\n| Ipn.c |\n| Ncurses demo  |\n-----------------\n\n");
    refresh();

    addstr("\npresiona cualquier tema para salir...");
    refresh();

    getch();

    endwin();

    return EXIT_SUCCESS;
}
