#include <iostream>
#include <fstream>
#include <omp.h>
#include "utils/array_tools.h"
#include "utils/partial_sum.h"

using namespace std;

int main()
{
	int size, *array, *array_temp, *array_temp_parallel;
	double start, end, start_parallel, end_parallel;

	start = end = start_parallel = end_parallel = 0;
	size = 1;
	while ((end - start) <= (end_parallel - start_parallel))
	{
		size++;
		array = array_create_random(size);

		start = omp_get_wtime();
		array_temp = partial_sum(array, size);
		end = omp_get_wtime();

		start_parallel = omp_get_wtime();
		array_temp_parallel = partial_sum_parallel(array, size);
		end_parallel = omp_get_wtime();

		delete[] array;
		delete[] array_temp;
		delete[] array_temp_parallel;
	}

	ofstream out;
	out.open("./parallel_level.txt");
	out << size << endl;
	out.close();

	return 0;
}