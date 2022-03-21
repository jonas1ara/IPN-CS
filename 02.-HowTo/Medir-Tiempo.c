#include <stdio.h>
#include <sys/time.h>

int main () {
    double sum = 0;
    double add = 1;

    // Comienza a medir tiempo
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    ///////Código a medir/////////
    
    
    // Detiene la medición de tiempo y retiene la medida transcurrida
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    printf("Resultado: %.20f\n", sum);
    
    printf("Tiempo medido: %.3f segundos.\n", elapsed);
    
    return 0;
}
