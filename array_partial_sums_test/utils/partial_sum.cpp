#include "array_tools.h"
#include <iostream>
#include <omp.h>

long long int	*partial_sum_parallel(const long long int *array, unsigned int size, unsigned int thread_num);

long long int	*partial_sum(const long long int *array, unsigned int size)
{
	long long int	*result;

	result = new long long int [size];
	result[0] = array[0];
	for (unsigned int i = 1; i < size; i++)
		result[i] = result[i - 1] + array[i];

	return result;
}

long long int	*partial_sum_hybrid(const long long int *array, unsigned int size, unsigned int thread_num = 3)
{
	unsigned int	level;

	level = get_level();
	if (size >= level)
		return partial_sum_parallel(array, size, thread_num);
	return partial_sum(array, size);
}

long long int	*partial_sum_parallel(const long long int *array, unsigned int size, unsigned int thread_num = 3)
{
	long long int	*result;
	unsigned int	step;

	if (size < thread_num)
		thread_num = size;

	step = size / thread_num;

	result = new long long int[size];
	
	#pragma omp parallel num_threads(thread_num)
	{
		unsigned int	id = omp_get_thread_num();

		result[id * step] = array[id * step];

		for (unsigned int i = id * step + 1; i < id * step + step; i++)
			result[i] = result[i - 1] + array[i];
	}

	if (thread_num == 1)
		return result;

	for (unsigned int i = step + step - 1; i < size; i += step)
		result[i] += result[i - step];
	
	#pragma omp parallel num_threads(thread_num - 1)
	{
		unsigned int	id = omp_get_thread_num() + 1;

		for (unsigned int i = id * step; i < id * step + step - 1; i++)
			result[i] += result[(id - 1) * step + step - 1];
		
	}

	if ((size % thread_num) > 0)
	{
		result[thread_num * step] = array[thread_num * step];
		for (unsigned int i = thread_num * step + 1; i < thread_num * step + (size % thread_num); i++)
			result[i] = result[i - 1] + array[i];
		for (unsigned int i = thread_num * step; i < thread_num * step + (size % thread_num); i++)
			result[i] += result[thread_num * step - 1];
	}

	return result;
}
