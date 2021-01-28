#include "sort.h"

/**
 * bubble_sort - sorts array one item at a time
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int a, b;
	size_t j;

	while (1)
	{
		for (j = 0; j < size - 1; j++)
		{
			a = array[j];
			b = array[j + 1];
			if (a > b)
			{
				array[j] = b;
				array[j + 1] = a;
				print_array(array, size);
				break;
			}
		}
		if (j == size - 1)
			break;
	}
}
