#include "sort.h"

/**
 * heap_sort - sorts an array using the sift-down heap sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, last, temp;

	if (!array || size <= 1)
		return;
	last = (int)size - 1;
	for (last = (int)size - 1; last > 0; last--)
	{
		for (i = last; i >= 0; i--)
		{
			heapify(array, (int)size, i, last);
		}
		temp = array[0];
		array[0] = array[last];
		array[last] = temp;
		print_array((const int *)array, size);
	}
}

/**
 * heapify - recursively makes the array a max-heap
 * @array: the array is treated as a complete binary tree
 * @size: size of the array
 * @parent: index of the parent node (it will be compared with its children)
 * @last: index to mark the end of the unsorted part of the array
 */
void heapify(int *array, int size, int parent, int last)
{
	int left, right, temp;

	left = (parent * 2) + 1;
	right = (parent * 2) + 2;
	if (parent < 0 || parent >= size - 1)
		return;
	if (right <= last
			&& (array[right] >= array[left] && array[right] > array[parent]))
	{
		temp = array[parent];
		array[parent] = array[right];
		array[right] = temp;
		print_array((const int *)array, (size_t)size);
		heapify(array, size, right, last);
	}
	if ((left <= last && (right > last || array[left] > array[right]))
			&& array[left] > array[parent])
	{
		temp = array[parent];
		array[parent] = array[left];
		array[left] = temp;
		print_array((const int *)array, (size_t)size);
		heapify(array, size, left, last);
	}
}
