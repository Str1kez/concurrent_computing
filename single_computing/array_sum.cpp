#include <iostream>
#include "../utils/array_tools.h"

using namespace std;

long int	array_sum(const int *arr, unsigned int size)
{
	long int	sum;

	sum = 0;
	for (unsigned int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}

int	main()
{
	unsigned int	array_size;
	const int		*array;
	long int		sum;

	cout << "Set size of array" << endl;
	cin >> array_size;
	array = array_create(array_size);

	sum = array_sum(array, array_size);
	cout << "Sum of array = " << sum << endl;

	delete [] array;

	return 0;
}