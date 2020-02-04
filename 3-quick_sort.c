#include "sort.h"
/**
 *  swap - function to swap values in array
 *  @array: Array to sort
 *  @low: Starting index
 *  @high: Ending index
 *  @size: Size of the array
 *  Return: 1 if swap, 0 otherwise
 */
int swap(int *array, size_t low, size_t high, size_t size)
{
	int temp;

	if (high != low)
	{
		temp = array[low];
		array[low] = array[high];
		array[high] = temp;
		print_array(array, size);
		return (1);
	}
	return (0);
}
/**
 * validate - review if array is already sorted
 *  @array: array to sort
 *  @low: Starting index
 *  @high: Ending index
 *  Return: 1 if is not sorted, 0 otherwise
 */
int validate(int *array, size_t low, size_t high)
{
	size_t i;

	for (i = low; i < high; i++)
	{
		if (array[i] > array[i + 1])
			return (1);
	}
	return (0);
}
/**
 *  sort - sort the array
 *  @array: array to sort
 *  @low: Starting index
 *  @high: Ending index
 *  @size: size of the array
 */
void sort(int *array, size_t low, size_t high, size_t size)
{
	size_t j = low, i = j - 1;
	int piv = array[high], flag = 0, check_sort;

	for (j = low; j < high; j++)
	{
		if (array[j] <= piv)
		{
			i++;
			flag = swap(array, j, i, size);
		}
	}
	i++;
	flag = swap(array, j, i, size);

	if (flag == 0)
	{
		check_sort = validate(array, low, high);
		if (check_sort == 1)
			sort(array, low, high - 1, size);
	}
	else
	{
		sort(array, low, i, size);
		sort(array, i, high, size);
	}
}
/**
 * quick_sort - function that sorts an array of integers in ascending
 *              order using the Quick sort algorithm
 *  @array: array to sort
 *  @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t low;

	low = 0;
	if (size < 2 || array == NULL)
		return;
	sort(array, low, size - 1, size);
}
