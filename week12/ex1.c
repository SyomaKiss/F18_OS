#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fd;
	fd = fopen("/dev/urandom", "r");
	unsigned char c;// = malloc(sizeof(unsigned char));
	for(int i = 0; i<20; i++){
		c = fgetc(fd);
		printf("%c", c);
		fflush(stdout);
	}
	printf("\n");
	fclose(fd);

}
