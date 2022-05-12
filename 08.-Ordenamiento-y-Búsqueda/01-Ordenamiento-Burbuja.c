#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int list[MAX] = {1,8,4,6,0,3,5,2,7,9};

void display(){
   int i;
   printf("[");
	
   // navegar a traves de arreglo
   for(i = 0; i < MAX; i++) {
      printf("%d ",list[i]);
   }
	
   printf("]\n");
}

void bubbleSort() {
   int temp;
   int i,j;
   bool swapped = false;       
   
   // Recorrer todos los elementos del arreglo
   for(i = 0; i < MAX-1; i++) { 
      swapped = false;
		
      // Recorrer los números que se adelantan
      for(j = 0; j < MAX-1-i; j++) {
         printf("Elementos : [ %d, %d ] ", list[j],list[j+1]);

         // Checar si el número siguiente es menor que el actual
         //   Intercambiar los números 
         //  (Sube el número más alto) 
			
         if(list[j] > list[j+1]) {
            temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;

            swapped = true;
            printf(" => Intecarmbiado [%d, %d]\n",list[j],list[j+1]);
         } else {
            printf(" => No intercambiado\n");
         }
      }

      // Si no se intercambió ningún número, eso significa
      //  Arreglo ordenado, romper el ciclo. 
      if(!swapped) {
         break;
      }
      
      printf("Iteración %d#: ",(i+1)); 
      display();                     
   }    
}

int main() {
   printf("Arreglo de entrada: ");
   display();
   printf("\n");
   bubbleSort();
   printf("\nArreglo de salida: ");
   display();
}