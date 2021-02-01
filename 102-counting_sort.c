#include "sort.h"
#include <string.h>

/**
 * counting_sort - sorts an array of ints in ascending order using
 * counting sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: none
 */

void counting_sort(int *array, size_t size)
{
	int max, *count, i, size_int, *output;

	if (!array || size < 2)
		return;
	size_int = size;
	max = array[0];
	for (i = 1; i < size_int; ++i)
		if (array[i] > max)
			max = array[i];
	max = max + 1;
	count = malloc(sizeof(int) * max);
	if (!count)
		return;
	for (i = 0; i < max; ++i)
		count[i] = 0;

	for (i = 0; i < size_int; ++i)
		++count[array[i]];

	for (i = 1; i < max; ++i)
		count[i] += count[i - 1];
	print_array(count, max);
	output = malloc(sizeof(int) * size_int);
	if (!output)
	{
		free(count);
		return;
	}
	for (i = size_int - 1; i >= 0; --i)
	{
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}
	for (i = 0; i < size_int; ++i)
		array[i] = output[i];
	free(count);
	free(output);
}
