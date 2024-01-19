#include "sort.h"
/**
 * bubble_sort - bubble sort algorithm
 *
 * @array: array to sort
 * @size: array size
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int temp;

	if (array == NULL)
		return;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}

