#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(){
	int *a;

	int who = RUSAGE_SELF;
	struct rusage usage;
	int ret;



	for (int i = 0; i < 10; i++){
		a = calloc(sizeof(char), 10*1024*1024);
		memset(a, 0, 10*1024*1024);
		ret = getrusage(who, &usage);
		printf("%ld: memory usage in mb\n", usage.ru_maxrss);
		sleep(1);
	}
}
