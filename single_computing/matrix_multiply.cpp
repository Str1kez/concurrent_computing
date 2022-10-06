#include <iostream>
#include "../utils/array_tools.h"

using namespace std;

int	main()
{
	unsigned int	row_size1, column_size1, row_size2, column_size2;
	int				**matrix1, **matrix2, **matrix_result;

	cout << "Set row size of first matrix" << endl;
	cin >> row_size1;
	cout << "Set column size of first matrix" << endl;
	cin >> column_size1;
	column_size2 = row_size1;
	cout << "Set row size of second matrix" << endl;
	cin >> row_size2;

	matrix1 = matrix_create(row_size1, column_size1);
	cout << endl;
	matrix_output(matrix1, row_size1, column_size1);

	matrix2 = matrix_create(row_size2, column_size2);
	cout << endl;
	matrix_output(matrix2, row_size2, column_size2);

	matrix_result = new int *[column_size1];
	for (unsigned int i = 0; i < column_size1; i++)
	{
		matrix_result[i] = new int [row_size2];
		for (unsigned int j = 0; j < row_size2; j++)
		{
			matrix_result[i][j] = 0;
			for (unsigned int x = 0; x < row_size1; x++)
				matrix_result[i][j] += matrix1[i][x] * matrix2[x][j];
		}
	}
	matrix_output(matrix_result, row_size2, column_size1);

	matrix_delete(matrix1, column_size1);
	matrix_delete(matrix2, column_size2);
	matrix_delete(matrix_result, column_size1);

	return 0;
}