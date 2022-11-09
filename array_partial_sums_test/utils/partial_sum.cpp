#include "array_tools.h"
#include <iostream>

int *partial_sum_parallel(const int *array, int size, unsigned int thread_num);

int *partial_sum(const int *array, int size)
{
	int *result;

	result = new int[size];
	for (int i = 0; i < size; i++)
		result[i] = 0;

	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++)
			result[i] += array[j];

	return result;
}

int *partial_sum_hybrid(const int *array, int size, unsigned int thread_num = 3)
{
	int level;

	level = get_level();
	if (size >= level)
		return partial_sum_parallel(array, size, thread_num);
	return partial_sum(array, size);
}

int *partial_sum_parallel(const int *array, int size, unsigned int thread_num = 3)
{
	int *result;

	result = new int[size];
	for (int i = 0; i < size; i++)
		result[i] = 0;

#pragma omp parallel for num_threads(thread_num)
	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++)
			result[i] += array[j];

	return result;
}
