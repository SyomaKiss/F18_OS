#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>


int main(){
	DIR *dirp = opendir("./tmp");
	struct dirent* dp;
	struct stat *buf = malloc(sizeof(struct stat));
	unsigned long long a[100], b[100];
	int i = 0, j = 0, jj = 0;
	char *s[100];
	int mask[100];
	while ((dp = readdir(dirp)) != NULL) {
//		printf("%s his inum: ", dp->d_name);
		s[j] = dp->d_name;
		char *p = malloc(100);
		strcat(p, "./tmp/");
		strcat(p, dp->d_name);
		stat(p, buf);
		//printf("%ld\n", buf->st_ino);
		a[j] = buf->st_ino;
		if (buf->st_nlink > 1) {
			mask[jj] = 1;
		} else mask[jj] = 0;
		jj++;
		j++;
	}
//	printf("%d\n", j);
	unsigned long long inum ;
	for(i = 0; i < j; i++){
	if (mask[i] > 0){
		printf("For index-node: %lld hard-link are {", a[i]);
		inum = a[i];
		mask[i] = 0;
		printf("%s ", s[i]);
		for (int k = 0; k < j; k++){
			if (mask[k] > 0 && a[k] == inum) {
				printf("%s ", s[k]);
				mask[k] = 0;
			}
		}
		printf("}\n");
	}
	}
(void)closedir(dirp);
return (2);
}
