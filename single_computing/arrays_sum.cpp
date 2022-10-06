#include <iostream>
#include "../utils/array_tools.h"

using namespace std;

int		*arrays_sum(const int *arr1, const int *arr2, unsigned int size)
{
	int	*sum;

	sum = new int [size];
	for (unsigned int i = 0; i < size; i++)
		sum[i] = arr1[i] + arr2[i];
	return sum;
}

int	main()
{
	unsigned int	array_size;
	const int		*array1, *array2;
	int				*sum;

	cout << "Set size of array" << endl;
	cin >> array_size;

	array1 = array_create(array_size);
	array2 = array_create(array_size);

	sum = arrays_sum(array1, array2, array_size);
	array_output(sum, array_size);

	delete[] array1;
	delete[] array2;
	delete[] sum;

	return 0;
}