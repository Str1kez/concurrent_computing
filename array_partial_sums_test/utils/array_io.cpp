#include <iostream>
#include <fstream>
#include <random>

using namespace std;

long long int	*array_create(unsigned int size)
{
	long long int	*array;

	array = new long long int [size];
	cout << "Enter the int elements of array" << endl;
	for (unsigned int i = 0; i < size; i++)
		cin >> array[i];

	return array;
}

long long int	*array_create_random(unsigned int size)
{
	long long int	*array;

	array = new long long int [size];
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(-1000, 1000);
	for (unsigned int i = 0; i < size; i++)
		array[i] = dist(mt);

	return array;
}

void			array_output(const long long int *arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

unsigned int	get_level()
{
	unsigned int	level;

	std::fstream fin;
	fin.open("./parallel_level.txt");
	if (!fin.is_open())
	{
		std::cout << "Can't open file" << std::endl;
		exit(1);
	}
	fin >> level;
	fin.close();

	return level;
}
