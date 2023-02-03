#include<stdio.h>
#include<stdlib.h>

#define TAMANIO 1000001

int main(void){
   int *ptr;
   //printf("%d   ",(rand() << 16) + rand());
   ptr=(int *)malloc(TAMANIO*sizeof(int));
   for(int i=0;i<TAMANIO;i++){
      *(ptr+i) = ((rand() << 16) + rand())%1000001;
   }
   for(int i=0;i<TAMANIO;i+=1000){
		printf("%d ",*(ptr+i));
   }
	
   return 0;
}
