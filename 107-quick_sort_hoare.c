#include "sort.h"

/**
 * partition - splits up elements into groups to be sorted and sorts
 * @array: array with ints to be sorted
 * @low: lowest array idx
 * @high: highest array idx
 * @size: size of array
 *  Return: idx of partition
 */

int partition(int *array, int low, int high, size_t size)
{
	int tmp, pivot, i = low - 1, j = high + 1;

	pivot = array[high];

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}


/**
 * real_quick - iterates sorting partitions
 * @array: array with ints to be sorted
 * @low: lowest array idx
 * @high: highest array idx
 * @size: size of array
 *  Return: none
 */

void real_quick(int *array, int low, int high, size_t size)
{
	int part;

	if (low < high)
	{
		part = partition(array, low, high, size);
		real_quick(array, low, part - 1, size);
		real_quick(array, part, high, size);
	}
}


/**
 * quick_sort_hoare - wrapper function that calls sort functions
 * @array: array with ints to be sorted
 * @size: size of array
 *  Return: none
 */

void quick_sort_hoare(int *array, size_t size)
{
	int low, high;

	if (!array || size < 2)
		return;

	low = 0;
	high = size - 1;
	real_quick(array, low, high, size);
}
