#include "sort.h"

/**
 * swapInts - Swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 * Return: nothing
 */
void swapInts(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: An array of integers to sort
 * @size: The size of the array
 * Return: nothing
 * Description: Prints the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, i;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (index = 0; index < size - i - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				swapInts(&array[index], &array[index + 1]);
				print_array(array, size);
			}
		}
	}
}
