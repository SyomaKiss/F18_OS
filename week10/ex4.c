#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>


int main(){
	DIR *dirp = opendir("./tmp");
	//DIR *dirp = opendir(".");
	if (dirp == NULL) { return (1); }
	char *name = "tmp";
 	int len = strlen(name);
	struct dirent* dp;
	struct stat *buf = malloc(sizeof(struct stat));

	while ((dp = readdir(dirp)) != NULL) {
//		printf("%s his inum: ", dp->d_name);
		char *p  = malloc(100);
		strcat(p, "./tmp/");
		strcat(p, dp->d_name);
		stat(p, buf);
//		printf("%ld\n", buf->st_nlink);
		if (buf->st_nlink > 1) {
			printf("%s\n", dp->d_name);
		}
	}

(void)closedir(dirp);
return (2);
}
