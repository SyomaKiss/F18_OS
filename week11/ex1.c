#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define FILEPATH "ex1.txt"

int main(){
	char *new = "Have a nice day, my TA!";
	struct stat* finfo = malloc(sizeof(struct stat));
	int fd = open(FILEPATH, O_RDWR);
	stat(FILEPATH, finfo);
	int fsize = finfo->st_size;
//	printf("%d %ld\n", fsize, strlen(new));
	printf("truncate result: %d\n", ftruncate(fd, strlen(new)));
	void *map = mmap(FILEPATH, strlen(new), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	memcpy(map, new, strlen(new));
	msync(map, strlen(new), MS_SYNC);
	munmap(map, strlen(new));
	close(fd);
}

