#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <stdio.h>
#include "ui.h"
#include "matrix.h"

#define IT 300
#define REFRESH_DELAY 50000L

int main(int argc, char **argv)
{
    if (!init_ui())
    {
        return EXIT_FAILURE;
    }

    matrix_init();

    for (int i = 0; i < IT; i++)
    {
        matrix_update();
        show_matrix();
        usleep(REFRESH_DELAY);
    }
    
    cleanup_ui();
    return EXIT_SUCCESS;

}