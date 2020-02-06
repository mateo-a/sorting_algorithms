#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in ascending order
 *               using the Shell sort algorithm, using the Knuth sequence
 *  @array: array to sort
 *  @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, j, i;
	int temp, flag;

	if (array == NULL || size < 1)
		return;
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;
	for (; gap > 0; gap = gap / 3)
	{
		flag = 0;
		for (j = gap; j < size; j += 1)
		{
			temp = array[j];
			for (i = j; i >= gap && array[i - gap] > temp; i -= gap)
			{
				array[i] = array[i - gap];
			}
			array[i] = temp;
			flag = 1;

		}
		if (flag == 1)
			print_array(array, size);
	}
}
