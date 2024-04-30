#include <stdio.h>
#include "sort.h"

void quick_sort_recursion(int *array, size_t n, int high, int low);
void swap(int *a, int *b);
int partition(int *array, size_t n, int low, int high);

/**
 * quick_sort - Sort an array of integers.
 * @array: An array of integers.
 * @n: Size of the array.
 *
 * Description: Quick sort algorithm.
 */
void quick_sort(int *array, size_t n)
{
	quick_sort_recursion(array, n, 0, n - 1);
}


/**
 * partition - Splits the array into two partitions.
 * @array: An array of integers.
 * @size: Size of the array.
 * @left: The array below the pivot.
 * @right: The array above the pivot.
 *Return: The index of the pivot.
 *
**/
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}


/**
 * swap - Swap two integers.
 * @a: A pointer to the first integer.
 * @b: A pointer to the second integer.
 *
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}



/**
 * quick_sort_recursion - Sort the array using recursion.
 * @array: An array of integers.
 * @n: The size of the array.
 * @low: Lowest index of the array.
 * @high: Highest index of the array.
 *
 */
void quick_sort_recursion(int *array, size_t n, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, n, low, high);
		quick_sort_recursion(array, n, low, pivot - 1);
		quick_sort_recursion(array, n, pivot + 1, high);
	}
}
