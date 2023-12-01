#include "quicksort.h"

int partition(int *array, int lo, int hi)
{
	int pivot = array[hi];

	int i = lo - 1;

	for (int j = lo; j < hi; j++) {
		if (array[j] <= pivot) {
			i++;
			int tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
	}

	i++;
	int tmp = array[i];
	array[i] = array[hi];
	array[hi] = tmp;

	return i;
}

void quicksort(int *array, int lo, int hi)
{
	if (lo >= hi || lo < 0) {
		return;
	}

	int p = partition(array, lo, hi);

	quicksort(array, lo, p - 1);
	quicksort(array, p + 1, hi);
}
