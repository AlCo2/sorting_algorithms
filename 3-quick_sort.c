#include "sort.h"

/**
 *quick_sort - Sorts an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: The array to be sorted
 *@size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/*Call the recursive sorting function */
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 *quick_sort_recursive - Recursive function to perform the Quick sort
 *@array: The array to be sorted
 *@low: The low index of the partition
 *@high: The high index of the partition
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		/**
		 *Find pivot element such that elements smaller
		 *than pivot are on the left and greater on the right
		 */
		int pivot_index = partition(array, low, high, size);

		/*Recursively sort the sub-arrays */
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 *partition - Partitions the array and returns the pivot index
 *@array: The array to be sorted
 *@low: The low index of the partition
 *@high: The high index of the partition
 *
 *Return: The index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			/*Swap array[i] and array[j] */
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
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
