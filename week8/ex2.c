#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	int *a;
	for (int i = 0; i < 10; i++){
		a = calloc(sizeof(char), 10*1024*1024);
		memset(a, 0, 10*1024*1024);
		sleep(1);
	}
}
