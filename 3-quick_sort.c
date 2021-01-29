#include "sort.h"

/**
 *
 *
 *
 *
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, tmp, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	if (i + 1 != high)
	    print_array(array, size);
	return (i + 1);
}

void real_quick(int *array, int low, int high, size_t size)
{
	int part;

	if (low < high)
	{
		part = partition(array, low, high, size);
		real_quick(array, low, part - 1, size);
		real_quick(array, part + 1, high, size);
	}
}

void quick_sort(int *array, size_t size)
{
	int low, high;

	low = 0;
	high = size - 1;
	real_quick(array, low, high, size);
}
