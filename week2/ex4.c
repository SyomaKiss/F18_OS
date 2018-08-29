#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int z, c;
    printf("Please, enter two integers:");
    scanf("%d %d", &z, &c);
    printf("%d %d\n", z, c);
    swap(&z, &c);
    printf("%d %d", z, c);
    return 0;
}

void swap(int *n, int *m) {
    int t;
    t = *n;
    *n = *m;
    *m = t;
}
