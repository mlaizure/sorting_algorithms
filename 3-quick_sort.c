#include "sort.h"

int partition(int *array, int low, int high, size_t size);
void real_quick(int *array, int low, int high, size_t size);

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
	int pivot, tmp, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
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
		real_quick(array, part + 1, high, size);
	}
}


/**
 * quick_sort - wrapper function that calls sort functions
 * @array: array with ints to be sorted
 * @size: size of array
 *  Return: none
 */

void quick_sort(int *array, size_t size)
{
	int low, high;

	if (!array || size < 2)
		return;

	low = 0;
	high = size - 1;
	real_quick(array, low, high, size);
}
