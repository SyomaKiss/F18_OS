#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char command[100];
	while (1){
		printf("> ");
		fgets(command, 100, stdin);
		printf("< ");
		system(command);
	}
	return 1;
}
