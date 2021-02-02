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
	int bucket[10][10], bucket_cnt[10], i, j, k, r, NOP = 0, div = 1, max;
	int pass, nsize = size;

	max = get_max(array, size);

	while (max > 0)
	{
		NOP++;
		max /= 10;
	}

	printf("Before for loop\n");
	for (pass = 0; pass < NOP; pass++)
	{
		printf("Inside main for loop\n");
		for (i = 0; i < 10; i++)
			bucket_cnt[i] = 0;
		for (i = 0; i < 10; i++)
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
}
