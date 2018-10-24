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
	unsigned long long a[100]; //i-node for each file in dir
	int j = 0;
	char *s[100];  //names of files
	int mask[100]; // which file appears more then twice
	while ((dp = readdir(dirp)) != NULL) {
		s[j] = dp->d_name;
		char *p = malloc(100);
		strcat(p, "./tmp/");
		strcat(p, dp->d_name);
		stat(p, buf);
		a[j] = buf->st_ino;
		if (buf->st_nlink > 1) {
			mask[j] = 1;
		} else mask[j] = 0;
		j++;
	}
	unsigned long long inum ;
	for(int i = 0; i < j; i++){
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
