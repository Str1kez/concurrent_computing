#include <iostream>
#include <omp.h>
#include "utils/array_tools.h"

using namespace std;

int	*partial_sum(const int *array, int size, unsigned int thread_num=3)
{
	int	*result;

	result = new int [size];
	for (int i = 0; i < size; i++)
		result[i] = 0;

	#pragma omp parallel for num_threads(thread_num)
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			result[i] += array[j];
		cout << omp_get_thread_num() << endl;
	}

	return result;
}

int main()
{
	int	size, *array, *array_temp;
	cout << "Enter size of array: \t";
	cin >> size;
	array = array_create(size);

	array_temp = partial_sum(array, size, 1);

	array_output(array_temp, size);
	delete[] array;
	delete[] array_temp;
	return 0;
}
