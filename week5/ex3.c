#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define N 2
#define is_parallel 0
#define MAX 10

time_t last_print;
int buffer = 0;
int producer_sleep = 0;
int consumer_sleep = 0;

void myprint(char *s){
	if (time(NULL) - last_print > 2){
		printf("%s\n", s);
		last_print = time(NULL);
	}
}

void *producer_routine(void *tid){
	while (1){
		if (!producer_sleep && buffer < MAX){
			buffer++;
			consumer_sleep = 0;
		}else
			producer_sleep = 1;
	}
	myprint("producer is here");
	pthread_exit(NULL);
}

void *consumer_routine(void *tid){
	while (1){
		if (!consumer_sleep && buffer > 0){
			buffer--;
			producer_sleep = 0;
		}else
			consumer_sleep = 1;
	}
	pthread_exit(NULL);
}

int main(){
	last_print = time(NULL);
	pthread_t threads[N];
	int status[N];

	status[0] = pthread_create(&threads[0], NULL,consumer_routine, (void *)0);
	status[1] = pthread_create(&threads[1], NULL,producer_routine, (void *)1);

	pthread_join(threads[0], NULL);	
	pthread_join(threads[1], NULL);

	
	exit(0);
}
