// #include <stdio.h>

// #define max 7

// int arr[8] = {5,4,8,7,6,1,2,3};
// int aux[7];

// void Sort( int inicio, int final);
// void Merge(int inicio, int m, int final);

// int main()
// {
// 	int i;

// 	printf("Insorted: \n");
// 	for(i=0; i <= max; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");

// 	Sort(0, max);
		
// 	printf("Sorted by Merge Sort: \n");
// 	for(i=0; i <= max; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// }

// void Sort(int inicio, int final)
// {
// 	int m;
// 	if(inicio<final)
// 	{
// 		m = (inicio+final)/2;
// 		Sort(inicio, m);	
// 		Sort(m+1, final);
// 		Merge(inicio, m, final);
// 	} else {return;}
// }

// void Merge(int inicio, int m, int final) {
//    int l1, l2, i;

//    for(l1 = inicio, l2 = m + 1, i = inicio; l1 <= m && l2 <= final; i++) {
//       if(arr[l1] <= arr[l2])
//          aux[i] = arr[l1++];
//       else
//          aux[i] = arr[l2++];
//    }
   
//    while(l1 <= m)    
//       aux[i++] = arr[l1++];

//    while(l2 <= final)   
//       aux[i++] = arr[l2++];

//    for(i = inicio; i <= final; i++)
//       arr[i] = aux[i];
// }

#include <stdio.h>

#define max 10

int a[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int main() { 
   int i;

   printf("List before sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   sort(0, max);

   printf("\nList after sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}

