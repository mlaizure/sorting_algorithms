#include "sort.h"

/**
 * selection_sort - sorts an array of ints in ascending order using the
 * Selection sort algorithm
 * @array: array of ints to sort
 * @size: size of array
 * Return: none
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0, min_idx = 0;
	int tmp;

	while (1)
	{
		for (i = 0; i < size - 1; ++i)
		{
			min_idx = i;
			for (j = i + 1; j < size; ++j)
				if (array[j] < array[min_idx])
					min_idx = j;
			if (i != min_idx)
			{
				tmp = array[i];
				array[i] = array[min_idx];
				array[min_idx] = tmp;
				print_array(array, size);
			}
		}
		k = 0;
		while (k < size - 2 && array[k] < array[k + 1])
			++k;
		if (k == size - 2)
			break;
	}
}
