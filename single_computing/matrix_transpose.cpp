#include <iostream>
#include "utils/array_tools.h"

using namespace std;

int		**matrix_transpose(int **matrix, unsigned int row_size, unsigned int column_size)
{
	int	**transposed;

	transposed = new int *[row_size];

	for (unsigned int i = 0; i < row_size; i++)
	{
		transposed[i] = new int [column_size];
		for (unsigned int j = 0; j < column_size; j++)
			transposed[i][j] = matrix[j][i];
	}

	return transposed;
}

int	main()
{
	unsigned int	row_size, column_size;
	int				**matrix, **transposed_matrix;

	cout << "Set row size of matrix" << endl;
	cin >> row_size;
	cout << "Set column size of matrix" << endl;
	cin >> column_size;
	matrix = matrix_create(row_size, column_size);
	matrix_output(matrix, row_size, column_size);

	transposed_matrix = matrix_transpose(matrix, row_size, column_size);
	matrix_output(transposed_matrix, column_size, row_size);
	cout << endl;

	matrix_delete(matrix, column_size);
	matrix_delete(transposed_matrix, row_size);

	return 0;
}