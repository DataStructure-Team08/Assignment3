#include "common.h"

int* array(int n) {
	int* arr;

	arr = (int*)malloc(sizeof(int) * n);

	return arr;
}
void print_array(int* a, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void freeArray(int* arr) {
	free(arr);
}

int mrand(int range) {
	return rand() % range;
}