#include "sort.h"

/**
 * get_max - gets max value's number of places
 * @a: array
 * @size: size of array
 * Return: number of places
 */

int get_max(int *a, size_t size)
{
	size_t i, NOP = 0;
	int max = a[0];

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
	int **bucket, *bucket_cnt, i, j, k, r, NOP = 0, div = 1;
	int pass, nsize = size, z;

	if (!array || size < 2)
		return;
	NOP = get_max(array, size);
	if (nsize < NOP)
		z = NOP;
	else
		z = nsize;
	bucket_cnt = malloc(sizeof(int) * z);
	bucket = malloc(sizeof(int) * NOP * z);
	for (i = 0; i < nsize; i++)
		bucket[i] = malloc(sizeof(int) * NOP);
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < z; i++)
			bucket_cnt[i] = 0;
		for (i = 0; i < z; i++)
		{
			r = (array[i] / div) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < nsize; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++, i++)
				array[i] = bucket[k][j];
		}
		div *= 10;
		print_array(array, size);
	}
	free(bucket_cnt);
	for (i = 0; i < nsize; i++)
		free(bucket[i]);
	free(bucket);
}
