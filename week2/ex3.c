#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int i, n;
    sscanf(argv[1], "%d", &n);
    for (i = 0; i < n ; i++) {
        triangle(i, n);
    }
    return 0;
}

void triangle(int k, int n) {
    int i;
    for (i = 0; i < n * 2 -1; i++) {
        if (i < n - k -1 || i > 2*n-1 - (n-k)) printf(" ");
        else printf("*");
    }
    printf("\n");
}
