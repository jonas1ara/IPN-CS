#include <stdio.h>

#define MAX 8

int arr[MAX] = {35, 33, 42, 10, 14, 19, 27, 44};

void imprimirArreglo() 
{
   printf("[");	
   // Navegar a través de todos los elementos del arreglo
   for(int i = 0;i < MAX;i++) {
      printf("%d ",arr[i]);
   }
	
   printf("]\n");
}

void imprimirLineas(int count) 
{	
   for(int i = 0;i < count-1;i++) {
      printf("=");
   }
	
   printf("=\n");
}

void ordenamiento_Shell() {
   int inicio, final;
   int valor_a_insertar;
   int intervalo = 1;  // Intervalo de desplazamiento
   int elementos = MAX;
   int i = 0;
   
   while(intervalo <= elementos/3) // Mientras el intervalo sea menor o igual a un tercio del arreglo 
   {
   		//Ecuación de knuth, para calcular el intervalo
      intervalo = intervalo*3 +1;
   }
	//Mientras el intervalo sea mayor a 0
   while(intervalo > 0) {
      printf("iteración #%d:",i); 
      imprimirArreglo();
      for(final = intervalo; final < elementos; final++) 
      {
      //se asigna el valor del elemento a insertar
         valor_a_insertar = arr[final];
         inicio = final;
	//Mientras inicio sea mayor que intervalo -1, y el valor del elemento a insertar sea menor que el elemento en la posición inicio
         while(inicio > intervalo -1 && arr[inicio - intervalo] 
            >= valor_a_insertar) 
         {
         //Se asigna el valor del elemento en la posición inicio - intervalo al elemento en la posición inicio
            arr[inicio] = arr[inicio - intervalo];
            //Se decrementa inicio en intervalo
            inicio -= intervalo;
            //inicio = inicio - intervalo;
            printf(" Elemento movido: %d\n",arr[inicio]);
         }
         //Se asigna el valor del elemento a insertar en la posición inicio
         arr[inicio] = valor_a_insertar;
         printf(" Elemento insertado:%d, en la posición :%d\n",valor_a_insertar,inicio);
      }
		
      intervalo = (intervalo -1) /3;
      i++;
   }          
}

int main() 
{
   printf("Ordenamiento Shell con complejidad O(n) ...\n");
   printf("Arreglo de entrada: ");
   imprimirArreglo();
   imprimirLineas(50);
   ordenamiento_Shell();
   printf("Arreglo de salida: ");
   imprimirArreglo();
   imprimirLineas(50);
   return 0;
}