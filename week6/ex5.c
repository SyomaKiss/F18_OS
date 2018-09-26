#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

void kill_handler(int n){
	printf("Oops, I am dead:(\n");
	exit(1);
}

int main()
{
	int fd[2], nbytes;
        pid_t childpid;        
        pipe(fd);
	char buff[100];
	        
        char *str1 = "String, that was written in parent";
	char str2[20];
	
	childpid = fork();
	if (childpid == 0){
		signal(SIGTERM, kill_handler);
		while (1){
			printf("I am alive!\n");
			sleep(1);
			fflush(stdout);
		}
		
	} else {
		sleep(10);
		printf("I'll kill you 'Batch'\n");
		kill(childpid, SIGTERM);		
	}		
}
