#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Page{
	char counter;
	int number;
	int referenced;
} Page;

int least_one(Page *table){
	unsigned int min = 4294967296/2 - 1;
	int n = 0;
	for(int i = 0; i<MAX; i++){
//		printf("%d [%d] ", min, table[i].counter);
		if (table[i].counter < min){
			min = table[i].counter;
			n = i;
//			printf("%d %d\n", min, n);
		}
	}
	return n;
}
int is_hit(Page *table, int p_n){
//	printf("%d  h\n", p_n);
	for(int i = 0; i<MAX; i++){
		if (table[i].number == p_n){
			return p_n;
		}
	}
	return 0;
}
void shift_all(Page *table){
	for(int i = 0; i<MAX; i++){
		table[i].counter = table[i].counter >> 1;
		table[i].referenced = 0;
	}
}

int main(){
	int page_number = 0, m = 0, first_available = 0;
	int page_index = 0, i = 0;
	Page *table;
	table = malloc(sizeof(Page)*MAX);
	for (int i = 0; i<MAX; i++){
		table[i].counter = 0;
		table[i].referenced = 0;
		table[i].number = 0;
	}
//	printf("\n%d least counter from\n", m);
	int hit = 0;
	int miss = 0;
	FILE* file = fopen("input.txt", "r");
	while (!feof(file)){
		fscanf(file,"%d", &page_number);
		i++;
		if  (i >= 1001) break;
		//printf("index: %d pageN: %d\n", i, page_number);
		//body
		shift_all(table);
		if (page_index = is_hit(table,page_number)){
			//page_index = is_hit(table,page_number);
			hit++;
			table[page_index].referenced = 1;
			table[page_index].counter = table[page_index].counter | (1<<7);
		//	printf("hit");
			

		} else {
			if (first_available < MAX ){
			table[first_available].counter = 1 << 7;
			table[first_available].referenced = 1;
			table[first_available].number = page_number;
			miss++;
			first_available++;
//			printf("miss");
			} else {
				m = least_one(table);
				table[m].counter = (1 << 7);
				table[m].referenced = 1;
				table[m].number = page_number;
				miss++;
//				printf("miss2");
			}
		}
	
	}

	printf("hit rate %d\n", hit);
	printf("miss rate %d\n", miss);
	fclose(file);
}
