#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, char* argv[]){
	FILE ** files = malloc(sizeof(FILE)*20);
	int is_append = 0;
	if (strcmp(argv[1], "-a") == 0){
		is_append = 1;
	}
	for (int i = 1; i < argc; i++){
//		printf("%s ", argv[i]);
		files[i+is_append] = fopen(argv[i], "w");
	}
	char *buffer = malloc(100);

	while (fread(buffer, 1, BUFFER_SIZE, stdin)){
		for (int i = 1; i < argc; i++){
			fwrite(buffer, 1, BUFFER_SIZE, files[i+is_append]);
		}
		printf("%s", buffer);
	}
}
