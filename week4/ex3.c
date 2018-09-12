#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char command[30];
	while (1){
		printf("> ");
		scanf("%s", command);
		system(command);
	}
	return 1;
}
