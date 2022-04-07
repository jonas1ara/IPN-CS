#include <stdio.h>
#include <pthread.h>

void* routine()
{
	printf("Test from thread 1\n");
}
void* routine2()
{
	printf("Test from thread 2 \n");
}

int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, routine, NULL);
	pthread_create(&t2, NULL, routine2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
 
	return 0;
}