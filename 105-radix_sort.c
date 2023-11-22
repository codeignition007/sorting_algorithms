#include "sort.h"

void radix_counting_sort(int *array, size_t size, int sig, int *buff);
int get_max(int *array, int size);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get maximum value in array of integers.
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Return: Maximum integer in array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort significant digits of an array of integers
 *                       in ascending order using counting sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 * @sig: Significant digit to sort on.
 * @buff: Buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort array of integers in ascending order
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Description: Implements LSD radix sort algorithm. Prints
 * array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
