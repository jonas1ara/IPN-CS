#include <stdio.h>

#define max 7

int arr[8] = {5,4,8,7,6,1,2,3};
int aux[7];

void Sort( int inicio, int final);
void Merge(int inicio, int m, int final);

int main()
{
	int i;

	printf("Insorted: \n");
	for(i=0; i <= max; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	Sort(0, max);
		
	printf("Sorted by Merge Sort: \n");
	for(i=0; i <= max; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Sort(int inicio, int final)
{
	int m;
	if(inicio<final)
	{
		m = (inicio+final)/2;
		Sort(inicio, m);	
		Sort(m+1, final);
		Merge(inicio, m, final);
	} else {return;}
}

void Merge(int inicio, int m, int final) {
   int l1, l2, i;

   for(l1 = inicio, l2 = m + 1, i = inicio; l1 <= m && l2 <= final; i++) {
      if(arr[l1] <= arr[l2])
         aux[i] = arr[l1++];
      else
         aux[i] = arr[l2++];
   }
   
   while(l1 <= m)    
      aux[i++] = arr[l1++];

   while(l2 <= final)   
      aux[i++] = arr[l2++];

   for(i = inicio; i <= final; i++)
      arr[i] = aux[i];
}



