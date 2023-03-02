#include "prueba.h"

static void prueba2(int *x)
{
    *x += 10;
}

void prueba(int *x)
{
    *x += 10;
    prueba2 (x); 
}