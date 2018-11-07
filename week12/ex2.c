#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, char* argv[]){
	FILE ** files = malloc(sizeof(FILE)*20);
	int is_append = 0;
	char * open_mod = "w";
	if (strcmp(argv[1], "-a") == 0){
		is_append = 1;
		open_mod = "a";
	}
	files[0] = stdout;
	for (int i = 1+is_append; i < argc; i++){
		files[i-is_append] = fopen(argv[i], open_mod);
	}
	argc = argc - is_append;
	char *buffer = malloc(BUFFER_SIZE);
	int max = BUFFER_SIZE;
	while (fread(buffer, 1, BUFFER_SIZE, stdin)){
		for (int i = 0; i < BUFFER_SIZE; i++){
			if (buffer[i] == '\0') {
				max = i;
				break;
			}
		}
		for (int i = 0; i < argc; i++){
			fwrite(buffer, 1, max, files[i]);
		}
		//printf("%s", buffer);
	}
	for (int i = 0; i < argc; i++){
		fclose(files[i]);
	}
}
