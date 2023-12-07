#include "binary_search.h"

bool binary_search(int *array, int length, int item)
{
	int lo = 0;
	int hi = length - 1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int guess = array[mid];

		if (guess == item) {
			return true;
		}
		if (guess > item) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return false;
}

