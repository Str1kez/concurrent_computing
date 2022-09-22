#include <iostream>
#include "utils/array_tools.h"

using namespace std;

long int	array_sum(const int *arr, unsigned int size)
{
	long int	sum;

	sum = 0;
	for (unsigned int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}

long int	matrix_sum(int **matrix, unsigned int row_size, unsigned int column_size)
{
	long int	sum;

	sum = 0;
	for (unsigned int i = 0; i < column_size; i++)
		sum += array_sum(matrix[i], row_size);
	return sum;
}

int	main()
{
	unsigned int	row_size, column_size;
	int				**matrix;
	long int		sum;

	cout << "Set row size of matrix" << endl;
	cin >> row_size;
	cout << "Set column size of matrix" << endl;
	cin >> column_size;
	matrix = matrix_create(row_size, column_size);

	sum = matrix_sum(matrix, row_size, column_size);
	cout << "Sum of matrix = " << sum << endl;

	matrix_delete(matrix, column_size);
	return 0;
}