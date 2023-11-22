#include "sort.h"

void hoare_sort(int *array, size_t size, int left, int right);
int hoare_partition(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 * swap_ints - Swap two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of array of integers
 *                   according to the hoare partition scheme.
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: Size of array.
 * @left: The starting index of array partition to order.
 * @right: The ending index of array partition to order.
 *
 * Description: Uses Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort array of integers in ascending order
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
