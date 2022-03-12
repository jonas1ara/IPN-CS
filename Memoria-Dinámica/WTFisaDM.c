#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf ("¯  _(ツ)_/¯ \n"); 

    int lucky = 23;

    printf("Value: %i \n",lucky);
    printf("Adress: %p \n",&lucky);

    char hello[] = "Hi Mom";

    char *str = malloc(4); //For bytes in memory

    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'y';
    str[3] = '\0';

    // all done now

    free(str);

    //Para datos complejos
    struct Humanoid
    {
        char dna[50];
        int age;
        float weight;
    };
    
    
    return 0;
}