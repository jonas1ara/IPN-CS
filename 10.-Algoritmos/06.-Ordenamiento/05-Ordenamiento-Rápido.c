#include <stdio.h>
#include <stdbool.h>

#define MAX 10
//35, 33, 42, 10, 14, 19, 27, 44

int arr[MAX] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};

void imprimirLineas(int count) 
{
   for(int i = 0;i < count-1;i++) 
   {
      printf("=");
   }
   printf("=\n");
}

void imprimirArreglo() 
{
   printf("[");	
   // Navegar a través del arreglo
   for(int i = 0;i < MAX;i++) {
      printf("%d ",arr[i]);
   }
   printf("]\n");
}

void intercambio(int num1, int num2) 
{
   int temp = arr[num1];
   arr[num1] = arr[num2];
   arr[num2] = temp;
}

int particion(int izquierdo, int derecho, int pivote) 
{
   int puntoIzquierdo = izquierdo -1;
   int puntoDerecho = derecho;

   while(true) {
      while(arr[++puntoIzquierdo] < pivote) 
      {
         //No hacer nada
      }
		
      while(puntoDerecho > 0 && arr[--puntoDerecho] > pivote) 
      {
         //No hacer nada
      }

      if(puntoIzquierdo >= puntoDerecho) 
      {
         break;
      } else 
      {
         printf("Elemento intercambiado :%d,%d\n", arr[puntoIzquierdo],arr[puntoDerecho]);
         intercambio(puntoIzquierdo,puntoDerecho);
      }
   }
	
   printf(" Pivote intercambiado :%d,%d\n", arr[puntoIzquierdo],arr[derecho]);
   intercambio(puntoIzquierdo,derecho);
   printf("   Arreglo actualizado: "); 
   imprimirArreglo();
   return puntoIzquierdo;
}

void ordenamiento_Rapido(int izquierdo, int derecho) 
{
   if(derecho-izquierdo <= 0) 
   {
      return;   
   } else 
   {
      int pivote = arr[derecho];
      int punto_de_particion = particion(izquierdo, derecho, pivote);
      ordenamiento_Rapido(izquierdo,punto_de_particion-1);
      ordenamiento_Rapido(punto_de_particion+1,derecho);
   }        
}

int main() 
{
   printf("Ordenamiento rápido con complejidad Ο(n log n) \n\n");
   printf("Arreglo de entrada: ");
   imprimirArreglo();
   imprimirLineas(50);
   ordenamiento_Rapido(0,MAX-1);
   printf("Arreglo de salida: ");
   imprimirArreglo();
   imprimirLineas(50);
}