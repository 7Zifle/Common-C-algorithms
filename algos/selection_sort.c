#include "selection_sort.h"

void selection_sort(int *array, int size)
{
	for (int i = 0; i < size - 1; i++) {
		int j_min = i;
		for (int j = i+1; j < size; j++) {
			if (array[j] < array[j_min]) {
				j_min = j;
				return;
			}
		}

		if (j_min != i)
		{
			int tmp = array[i];
			array[i] = array[j_min];
			array[j_min] = array[i];
		}
	}
}
