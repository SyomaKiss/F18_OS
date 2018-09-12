#include <stdio.h>
#include <unistd.h>

int main() {
	int n = 10;
//	printf("%d\n", fork());
	if (fork() == 0){
		printf("Hello from child[%d]\n", getpid());
	} else {
		printf("Hello from parent[%d]\n", getpid());
	}
		
	//printf("%d current\n", getpid());
	//printf("%d parent\n", getppid()); 
	return 0;
}
