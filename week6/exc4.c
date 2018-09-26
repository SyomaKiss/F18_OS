#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int);
void sigkill_handler(int);
void sigstop_handler(int);
void sigusr1_handler(int);

int main()
{
	signal(SIGINT, signal_handler);	
	signal(SIGKILL, sigkill_handler);	
	signal(SIGSTOP, sigstop_handler);	
	signal(SIGUSR1, sigusr1_handler);
	while(1) {
		printf("Forever loop iteration\n");
      		sleep(1); 
	}	
}

void signal_handler(int signal_number){
	printf("Caught signal %d, >ANY OTHER<\n", signal_number);
	exit(1);
}
void sigkill_handler(int signal_number){
	printf("Caught signal %d, >KILL<\n", signal_number);
	exit(1);
}
void sigstop_handler(int signal_number){
	printf("Caught signal %d, >STOP<\n", signal_number);
	exit(1);
}
void sigusr1_handler(int signal_number){
	printf("Caught signal %d,>USR1<\n", signal_number);
	exit(1);
}
