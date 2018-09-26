#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

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
		close(fd[1]);
		nbytes = read(fd[0], str2, 20);
		printf("Child received string: %s\n", str2);
	} else {
		close(fd[0]);
		write(fd[1], str1, 20);		
	}		
}
