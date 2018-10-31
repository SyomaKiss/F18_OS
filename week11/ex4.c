#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define FILE1 "ex1.memcpy.txt"
#define FILE2 "ex1.txt"
int main(){
	struct stat* fd_stat = malloc(sizeof(struct stat));
	struct stat* fs_stat = malloc(sizeof(struct stat));
	int fdd = open(FILE1, O_RDWR);
	int fds = open(FILE2, O_RDWR);
	stat(FILE1, fd_stat);
	stat(FILE2, fs_stat);

	printf("%ld %ld\n", fd_stat->st_size, fs_stat->st_size);
	printf("truncate result: %d\n", ftruncate(fdd, fs_stat->st_size));
	printf("%ld %ld\n", fd_stat->st_size, fs_stat->st_size);
	void *map_dst = mmap(FILE1, fd_stat->st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fdd, 0);
	void *map_src = mmap(FILE2, fs_stat->st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fds, 0);
	memcpy(map_dst, map_src, fs_stat->st_size);
//	msync(map, strlen(new), MS_SYNC);
	munmap(map_src, fs_stat->st_size);
	munmap(map_dst, fd_stat->st_size);
	close(fds);
	close(fdd);
}

