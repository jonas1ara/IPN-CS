#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
//Función principal
int main(void)
{
    initscr();

    addstr("-----------------\n| IPN-CS |\n| Ncurses Demo  |\n-----------------\n\n");
    refresh();

    addstr("\npresiona cualquier tecla para salir...");
    refresh();

    getch();

    endwin();

    return EXIT_SUCCESS;
}
