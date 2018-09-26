#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int);

int main()
{
	signal(SIGINT, signal_handler);	
	while(1) {
		printf("Going to sleep for a second...\n");
      		sleep(1); 
	}	
}

void signal_handler(int signal_number){
	printf("Caught signal %d, terminating ><\n", signal_number);
	exit(1);
}
