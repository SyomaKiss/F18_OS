#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp = fopen("input.txt", "r");
	int a* = malloc(10*4);
	int n = 0;
	char *c;
	// while (fscanf(fp, "%" c) != EOF){
			// printf("%s\n", *c);
	// }
	fscanf(fp, "%s", c) 
	
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}