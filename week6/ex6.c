#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void kill_handler(int n){
	printf("Oops, I am dead:(\n");
	exit(1);
}

int main()
{
	int fd[2];
        pid_t child_1, child_2;

        pipe(fd);
	child_1 = fork();
	printf("Parent created child 1\n");
	if (child_1){//parent
		child_2 = fork();
		printf("Parent created child 2\n");
		if (child_2){//parent
			int status;
			printf("Second child id passes in child 1\n");
			write(fd[1], &child_2, sizeof(child_2));
			waitpid(child_2, &status, 0);
			if (WIFEXITED(status)){
				printf("Norm %d\n", WEXITSTATUS(status));
			}
			printf("Status of child 2 received\n");
			exit(0);
		} else { //child 2
			exit(222);
		}
	} else { //child 1
		printf("Child 1 sleeps 2 seconds ..\n");
		sleep(2);
		printf("Child 1 wakes up ..\n");
		int childpid;
		close(fd[1]);
		read(fd[0], &childpid, sizeof(childpid));
		close(fd[0]);
		printf("Child 1 got PID of child 2\n");
		kill(childpid, SIGSTOP);
		printf("Child 1 sent SIGSTOP to child 1\n");
		exit(0);
	}
	return 0;
}
