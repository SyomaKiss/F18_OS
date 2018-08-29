#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
int i;
char *line = NULL, a;
size_t len = 0;
ssize_t read;
read = getline (&line, &len, stdin);
char out[len];
for (i = 0; i < strlen(line); i++){
	a = line[strlen(line)-1-i];
	out[i] = line[strlen(line)-1-i];
}
printf("%s\n", out);
}
