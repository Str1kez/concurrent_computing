#include <iostream>
#include <random>


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

int		**matrix_create(unsigned int row_size, unsigned int column_size)
{
	int	**matrix;

	matrix = new int *[column_size];
	for (unsigned int i = 0; i < column_size; i++)
	{
		matrix[i] = new int [row_size];
		cout << "Enter row elements:" << endl;
		for (unsigned int j = 0; j < row_size; j++)
			cin >> matrix[i][j];
	}

	return matrix;
}

void 	matrix_output(int **matrix, unsigned int row_size, unsigned int column_size)
{
	for (unsigned int i = 0; i < column_size; i++)
	{
		for (unsigned int j = 0; j < row_size; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

void	matrix_delete(int **matrix, unsigned int column_size)
{
	for (unsigned int i = 0; i < column_size; i++)
		delete [] matrix[i];
	delete [] matrix;
}

int		**matrix_init(unsigned int row, unsigned int column)
{
	int	**matrix;

	matrix = new int *[row];
	for (unsigned int i = 0; i < row; i++)
		matrix[i] = new int [column];

	return matrix;
}

void	generate_matrix(int **matrix, unsigned int row, unsigned int column)
{
	random_device rd;
	mt19937 mt(rd());;
	uniform_int_distribution<int> generate(-100, 100);
	for (unsigned int i = 0; i < row; i++)
	{
		for (unsigned j = 0; j < column; j++)
			matrix[i][j] = generate(mt);
	}
}
