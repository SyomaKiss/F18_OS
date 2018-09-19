#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


#define N 10
#define is_parallel 0

void *start_routine(void *tid){
	printf("Hello from thread %p\n", tid);
	pthread_exit(NULL);
}

void *producer_routine(void *tid){
	
}

int main(){
	pthread_t threads[N];
	int status;

	for(int i = 0; i < N; i++){
		printf("Creating thread %d\n", i);
		status = pthread_create(&threads[i], NULL,start_routine, (void *)i);
		if (!is_parallel){
			pthread_join(threads[i], NULL);
		}
		
		
		if (status != 0){
			printf("Error code from pthread_create %d\n", status);
			exit(-1);
		}
	}


	for (int i = 0; i < N; i++){
		if (is_parallel){
			pthread_join(threads[i], NULL);
		}
	
	}
	printf("exit program");
	exit(0);
}
