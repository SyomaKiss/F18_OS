#include <stdio.h>
#include <stdlib.h>
#define size 100

void swap(int *n, int *m) {
	int t;
	t = *n;
	*n = *m;
	*m = t;
}

void bubble_sort(int *a, int n){
	for (int i = 0; i < n-1; ++i)	{
		for (int j = 0; j < n-1-i; ++j)
		{
			if (a[j]>a[j+1]) swap(&a[j],&a[j+1]);
		}
	}
}

int main(){
	int a[size] = {5,3,2,1,6,34,23,12,34,35};
	int n = 10;
	for (int i = 0; i < n; ++i)	{
		printf("%d ", a[i]);
	}
	printf("\n");
	bubble_sort(a, n);
	for (int i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}

}

