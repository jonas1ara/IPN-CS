//Librería de constantes para el uso de la interfaz gráfica
#include <stdbool.h>

#ifndef _UI_H_
#define _UI_H_

#define MAXX 160
#define MAXY 50

#define MAX_INTENSITY 13
#define MIN_INTENSITY 4

typedef struct cell
{
    char char_value;
    int intensity;
 } cell;

//externo - definido en matrix.c
extern cell matrix[MAXX][MAXY];

bool init_ui();
void cleanup_ui();
void show_matrix();


#endif



