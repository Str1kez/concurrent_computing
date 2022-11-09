#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <thread>
#include <omp.h>
#include "utils/array_tools.h"
#include "utils/partial_sum.h"

using namespace std;

void printHistogram(int arr[], int n)
{
	int maxEle = *max_element(arr, arr + n);

	for (int i = maxEle; i >= 0; i--)
	{
		cout.width(2);
		cout << right << i << " | ";
		for (int j = 0; j < n; j++)
		{

			// if array of element is greater
			// then array it print x
			if (arr[j] >= i)
				cout << " x ";

			// else print blank spaces
			else
				cout << "   ";
		}
		cout << "\n";
	}

	// print last line denoted by ----
	for (int i = 0; i < n + 3; i++)
		cout << "---";

	cout << "\n";
	cout << "     ";

	for (int i = 0; i < n; i++)
	{
		cout.width(2); // width for a number
		cout << right << arr[i] << " ";
	}
}

int main()
{
	unsigned int processor_count;
	int size, *array, *array_temp, *hist;
	double start, end;

	processor_count = thread::hardware_concurrency();
	size = get_level() * 2;

	array = array_create_random(size);

	hist = new int[processor_count];

	// cout << "Thread count\tTime\t" << endl;

	for (unsigned int i = 1; i <= processor_count; i++)
	{
		start = omp_get_wtime();
		array_temp = partial_sum_hybrid(array, size, i);
		end = omp_get_wtime();
		// cout << i << "\t" << end - start << "\t" << endl;
		hist[i - 1] = (end - start) * 100000;
		delete[] array_temp;
	}

	printHistogram(hist, processor_count);

	delete[] array;
	delete[] hist;
	return 0;
}
