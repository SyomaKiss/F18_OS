/*
Semen Kiselev @All rights reserved
Used sources: 
https://gist.github.com/RenatoUtsch/4162787
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

int main(){
	
	int fd[2], nbytes;
	pipe(fd);
	char *string = "Message";
	char buf[80];
	pid_t pid = fork();

	if (pid  > 0 ){
		printf("Hello from Parent\n");
		// close(fd[0]);
		write(fd[1], string, strlen(string)+1); 
		printf("Message was written\n");
	} else {
		printf("hello from Child\n");
		// close(fd[1]);
		nbytes = read(fd[0], buf, sizeof(buf));
		printf("Message was read: %s\n", buf);
	}
}