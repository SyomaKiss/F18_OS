#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	int fd[2], nbytes;
                
        pipe(fd);
	char buff[100];
	        
        char *str1 = "String one";
	char str2[20];
	
	write(fd[1], str1, 20);
	nbytes = read(fd[0], str2, 20);

	printf("String [1] is transfered to string [2]: %s\n", str2);
	close(fd[1]);
	close(fd[0]);
        }
