#include <stdio.h>
#include <unistd.h>
int main(void) {
 printf("Hello");
//fflush(stdout);
 fork();
 printf("\n");
 return 0;
}
