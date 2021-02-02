#include "sort.h"

/**
 * get_max_NOP - gets number of places of max value in array
 * @a: array
 * @size: size of array
 * Return: number of places of max value in array
 */

int get_max_NOP(int *a, size_t size)
{
	size_t i;
	int max = a[0], NOP = 0;

	for (i = 1; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	while (max > 0)
	{
		NOP++;
		max /= 10;
	}
	return (NOP);
}

/**
 * radix_sort - sorts starting at smallest digit
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int *bucket[10], bucket_cnt[10], i, j, k, r, NOP = 0, div = 1;
	int pass, nsize = size;

	if (!array || size < 2)
		return;
	NOP = get_max_NOP(array, size);
	for (i = 0; i < 10; i++)
	{
		bucket[i] = malloc(sizeof(int) * nsize);
		if (!bucket[i])
		{
			for (j = 0; j < i; j++)
				free(bucket[j]);
			return;
		}
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
			bucket_cnt[i] = 0;
		for (i = 0; i < nsize; i++)
		{
			r = (array[i] / div) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++, i++)
				array[i] = bucket[k][j];
		}
		div *= 10;
		print_array(array, size);
	}
	for (i = 0; i < 10; ++i)
		free(bucket[i]);
}
