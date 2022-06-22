#include <stdio.h>
#include <stdbool.h>

#define MAX 10

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

//Función de intercambio, que recibe los valores ACTUALES del punto izquierdo y del punto derecho
void intercambio(int num1, int num2) 
{
   int temp = arr[num1]; //num1 = 35 --> temp = 35
   arr[num1] = arr[num2]; //num2 = 26 --> num1 = 26
   arr[num2] = temp; //temp = 35 --> num2 = 35
}
//Recibe un inicio y un final del arreglo
int particion(int izquierdo, int derecho, int pivote) 
{
   // Posicion punto izquierdo
   int puntoIzquierdo = izquierdo -1;
   // Posicion punto derecho
   int puntoDerecho = derecho;

   // Este ciclo while, se ejecuta mientras el arreglo no sea de un solo elemento, en cualquier arreglo o subarreglo
   while(true) 
   {
      //Mientras el punto izquierdo del arreglo sea menor que el pivote X < P
      while(arr[++puntoIzquierdo] < pivote) 
      {
         //Hacer nada, es decir ignorar el elemento y pasar al siguiente
      }
		//Mientras punto derecho del arreglo sea mayor a 0 y punto derecho sea mayor que el pivote X > P
      while(puntoDerecho > 0 && arr[--puntoDerecho] > pivote) 
      {
         //Hacer nada, es decir ignorar el elemento y pasar al siguiente
      }

      //Si el punto izquierdo es mayor o IGUAL que el punto derecho, terminar el ciclo
      if(puntoIzquierdo >= puntoDerecho) // inicio >= final, entonces terminar para intercambiar pivote, quiere decir si los puntos se encuentran en el mismo lugar ya no se puede comparar.
      {
         break;
      } else //Si el punto izquierdo sigue siendo menor que el punto derecho, intercambiar los elementos.
      {
         printf("Elemento intercambiado :%d,%d\n", arr[puntoIzquierdo],arr[puntoDerecho]);
         //llamada a función intercambio, pasando valores de punto izquierdo y punto derecho
         intercambio(puntoIzquierdo,puntoDerecho);
      }
   }
	//Cuando sale del ciclo, el punto izquierdo es mayor o igual que el punto derecho
   printf(" Pivote intercambiado :%d,%d\n", arr[puntoIzquierdo],arr[derecho]);
   //Intercambiar el elemento final con el pivote
   intercambio(puntoIzquierdo,derecho);
   printf("   Arreglo actualizado: ");  
   imprimirArreglo();
   return puntoIzquierdo; //punto izquierdo = 42, pero con el intercambio queda en el lugar del pivote y se retorna 31 el que era valor del pivote
}

void ordenamiento_Rapido(int izquierdo, int derecho) 
{

   //Lo que queremos lograr es que se seleccione un pivote, se particione el arreglo en dos con los elementos
   //menores a la izquiera y los mayores a la derecha.
   //Caso base
   if(derecho-izquierdo <= 0) //Si el arreglo tiene un solo elemento, no se puede particionar
   {
      return;   
   } else //Caso recursivo, de lo contrario, se puede particionar
   {
      //Seleccionar el pivote, el elemento final del arreglo o subarreglo
      int pivote = arr[derecho]; 
      //Particionar el arreglo llamando a la funcion particion y retornar el valor del punto izquierdo
      int punto_de_particion = particion(izquierdo, derecho, pivote); //Le pasamos los valores de inicio, final del arreglo y el pivote
      //Llamada recursiva para el subarreglo izquierdo, pero ahora con el punto de particion como nuevo limite y el valor de izquierdo como inicio
      ordenamiento_Rapido(izquierdo,punto_de_particion-1); //izquierdo = 0, punto_de_particion = 31
      //Llamada recursiva para el subarreglo derecho , pero ahorrar el valor del punto de particion como un nuevo inicio y el valor de derecho como final
      ordenamiento_Rapido(punto_de_particion+1,derecho); //punto_de_particion = 31, derecho = 9
   }        
}

int main() 
{
   printf("Ordenamiento rápido con complejidad Ο(n log n) \n\n");
   printf("Arreglo de entrada: ");
   imprimirArreglo();
   imprimirLineas(50);
   ordenamiento_Rapido(0,MAX-1); //Le pasas el inicio y el final del arreglo
   printf("Arreglo de salida: ");
   imprimirArreglo();
   imprimirLineas(50);
}