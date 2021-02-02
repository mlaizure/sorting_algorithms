#include "sort.h"

/**
 * get_max - gets max value in array
 * @a: array
 * @size: size of array
 * Return: largest int
 */

int get_max(int *a, size_t size)
{
	size_t i;
	int max = a[0];

	for (i = 1; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return (max);
}

/**
 * radix_sort - sorts starting at smallest digit
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int bucket[20][20], bucket_cnt[20], i, j, k, r, NOP = 0, div = 1, max;
	int pass, nsize = size;

	if (!array || size < 2)
		return;
	max = get_max(array, size);

	while (max > 0)
	{
		NOP++;
		max /= 10;
	}

	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 20; i++)
			bucket_cnt[i] = 0;
		for (i = 0; i < nsize; i++)
		{
			r = (array[i] / div) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 20; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++, i++)
				array[i] = bucket[k][j];
		}
		div *= 10;
		print_array(array, size);
	}
}
