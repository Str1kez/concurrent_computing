#include <iostream>
#include <omp.h>
#include "../utils/array_tools.h"

using namespace std;

int	main()
{
	unsigned int	row_count1, column_count1, row_count2, column_count2;
	int				**matrix1, **matrix2, **matrix_result, s;
	double			start, end;


	// cout << "Set row count of first matrix" << endl;
	// cin >> row_count1;
	// cout << "Set column count of first matrix" << endl;
	// cin >> column_count1;
	// row_count2 = column_count1;
	// cout << "Set column count of second matrix" << endl;
	// cin >> column_count2;

	row_count1 = column_count1 = column_count2 = row_count2 = 1000;

	matrix1 = matrix_init(row_count1, column_count1);
	generate_matrix(matrix1, row_count1, column_count1);
	// cout << endl;
	// matrix_output(matrix1, column_count1, row_count1);

	matrix2 = matrix_init(row_count2, column_count2);
	generate_matrix(matrix2, row_count2, column_count2);
	// cout << endl;
	// matrix_output(matrix2, column_count2, row_count2);

	matrix_result = matrix_init(row_count1, column_count2);

	if (row_count2 != column_count1)
		return 1;

	start = omp_get_wtime();
	for (unsigned int i = 0; i < row_count1; i++)
	{
		for (unsigned int j = 0; j < column_count2; j++)
		{
			s = 0;
			#pragma omp parallel for reduction(+: s)
			for (unsigned int x = 0; x < column_count1; x++)
				s += matrix1[i][x] * matrix2[x][j];
			matrix_result[i][j] = s;
		}
	}
	end = omp_get_wtime();
    // cout << "Result: \n";
	// for (unsigned int i = 0; i < row_count1; i++)
	// {
	// 	for (unsigned j = 0; j < column_count2; j++)
	// 		cout << matrix_result[i][j] << "\t";
	// 	cout << endl;
	// }
	cout << "Time for 3 example: " << end - start << endl;
	matrix_delete(matrix1, row_count1);
	matrix_delete(matrix2, row_count2);
	matrix_delete(matrix_result, row_count1);

	return 0;
}
