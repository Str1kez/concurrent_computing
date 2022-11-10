#include <iostream>
#include "utils/array_tools.h"
#include "utils/partial_sum.h"
#include <cmath>

using namespace std;

int main()
{
	unsigned int	size;
	long long int	*array_temp, *array;

	cout << "Enter size of array: \t";
	cin >> size;
	array = array_create_random(size);
	cout << "Origin array:" << endl;
	array_output(array, size);

	array_temp = partial_sum_parallel(array, size);

	cout << "Array of partial sum:" << endl;
	array_output(array_temp, size);
	delete[] array;
	delete[] array_temp;
	return 0;
}
