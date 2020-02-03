#include "sort.h"
/**
 *  swap - function to swap values in array
 *  @currentp: current position
 *  @nextp: next position
 */
void swap(int *currentp, int *nextp)
{
	int temp = *currentp;
	*currentp = *nextp;
	*nextp = temp;
}
/**
 * selection_sort - function that sorts an array of integers in ascending order
 *               using the Selection sort algorithm
 *  @array: array to sort
 *  @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL || size < 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
	min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;
		swap(&array[min_idx], &array[i]);
		if (min_idx != i)
			print_array(array, size);
	}
}

