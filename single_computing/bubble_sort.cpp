#include <iostream>
#include "../utils/array_tools.h"

using namespace std;


void	bubble_sort(int *arr, unsigned int size)
{
	int temp;

	for (unsigned int i = 1; i < size; i++)
		for (unsigned int j = 0; j < size - i; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

int main()
{
	unsigned int	array_size;
	int				*array;

	cout << "Set size of array" << endl;
	cin >> array_size;
	array = array_create(array_size);

	bubble_sort(array, array_size);
	array_output(array, array_size);

	delete [] array;
	return 0;
}
