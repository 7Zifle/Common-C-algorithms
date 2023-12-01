#include <stdio.h>

int arrcmp(int *first, int *second, int n)
{
	int diff = 0;
	for (int i = 0; i < n; i++) {
		diff += first[i] != second[i];
	}
	return diff;
}

void print_array(int *array, int n)
{
	printf("array[] = {");
	for (int i = 0; i < n; i++) {
		printf("%d, ", array[i]);
	}
	printf("};\n");
}
