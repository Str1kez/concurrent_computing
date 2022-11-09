#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int *array_create(unsigned int size)
{
	int *array;

	array = new int[size];
	cout << "Enter the int elements of array" << endl;
	for (unsigned int i = 0; i < size; i++)
		cin >> array[i];

	return array;
}

int *array_create_random(unsigned int size)
{
	int *array;

	array = new int[size];
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(-100, 100);
	for (unsigned int i = 0; i < size; i++)
		array[i] = dist(mt);

	return array;
}

void array_output(const int *arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

int get_level()
{
	int level;

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
