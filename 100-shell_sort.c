#include "sort.h"

/**
 * shell_sort - sorts pairs by interval
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 1, inner, outer;
	int val;

	if (!array || size < 2)
		return;
	while (interval <= size / 3)
		interval = interval * 3 + 1;

	for (; interval > 0; interval = (interval - 1) / 3)
	{
		for (outer = interval; outer < size; outer++)
		{
			val = array[outer];
			inner = outer;

			while (inner > interval - 1 && array[inner - interval]
			       >= val)
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}
			array[inner] = val;
		}
		print_array(array, size);
	}
}
