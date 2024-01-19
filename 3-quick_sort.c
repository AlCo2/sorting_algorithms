#include "sort.h"

/**
 *quick_sort - Sorts an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: The array to be sorted
 *@size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	/*Call the recursive sorting function */
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 *quick_sort_recursive - Recursive function to perform the Quick sort
 *@array: The array to be sorted
 *@low: The low index of the partition
 *@high: The high index of the partition
 *@size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 *partition - Partitions the array and returns the pivot index
 *@array: The array to be sorted
 *@low: The low index of the partition
 *@high: The high index of the partition
 *@size: Number of elements in the array
 *
 *Return: The index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			/*Swap array[i] and array[j] */
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 *swap - Swaps two elements in an array
 *@a: Pointer to the first element
 *@b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

