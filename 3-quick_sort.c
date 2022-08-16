#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: array of integers
 * @size: number of elements in array
 * Return: nothing
 * Description: implements Lomuto parittion scheme
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickerSort(array, size, 0, size - 1);
}

/**
 * quickerSort - does the actual recursive QuickSort
 * @array: array of integers
 * @size: number of elements in array
 * @min: first index of array
 * @max: last index of array
 * Return: nothing
 */
void quickerSort(int *array, size_t size, int min, int max)
{
	int index;

	if (min < max)
	{
		index = truncate(array, size, min, max);
		quickerSort(array, size, min, index - 1);
		quickerSort(array, size, index + 1, max);
	}
}

/**
 * truncate - truncate through an array of integers
 * @array: array of integers
 * @size: number of elements of array
 * @min: first index of array
 * @max: last index of array
 * Return: new index position
 * Description: all values must be accurate
 */
int truncate(int *array, size_t size, int min, int max)
{
	int pivot = array[max], index = min, i;

	for (i = min; i <= max - 1; i++)
	{
		if (array[i] < pivot)
		{
			if (index != i)
			{
				swap(&array[index], &array[i]);
				print_array(array, size);
			}
			index++;
		}
	}
	if (pivot != array[index])
	{
		swap(&array[index], &array[max]);
		print_array(array, size);
	}
	return (index);
}

/**
 * swap - swaps the address values of two pointers
 * @ptr_a: pointer to integer
 * @ptr_b: pointer to integer
 * Return: nothing
 */
void swap(int *ptr_a, int *ptr_b)
{
	int tmp;

	if (!ptr_a || !ptr_b)
		return;

	tmp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = tmp;
}
