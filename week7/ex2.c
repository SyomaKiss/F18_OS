#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int  *a;
	scanf("%d", &n);

	a = malloc(n*sizeof(int));
	for (int i = 0; i<n; i++){
		a[i] = i;
	}
	for (int i = 0; i<n; i++){
		printf("%d\n", a[i]);
	}
	free(a);
}
