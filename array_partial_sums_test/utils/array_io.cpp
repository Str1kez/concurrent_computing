#include <iostream>

using namespace std;

int		*array_create(unsigned int size)
{
	int	*array;

	array = new int [size];
	cout << "Enter the int elements of array" << endl;
	for (unsigned int i = 0; i < size; i++)
		cin >> array[i];

	return array;
}

void	array_output(const int *arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		cout << arr[i] << "\t";
}
