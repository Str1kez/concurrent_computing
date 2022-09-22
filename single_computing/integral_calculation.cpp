#include <iostream>
#include <cmath>


using namespace std;

double	*linspace(double start, double end, int count)
{
	double	*arr, step;

	arr = new double [count];
	step = (end - start) / (count - 1);

	for (int i = 0; i < count ; i++)
		arr[i] = start + i * step;

	return arr;
}

double	calculate_integral(double begin, double end, double (*func)(double))
{
	double *arr, sum;
	int		count;

	count = (int)(end - begin) * 500;
	arr = linspace(begin, end, count);

	sum = 0;
	for (int i = 1; i < count; i++)
		sum += (func(arr[i]) + func(arr[i - 1])) / 2 * (arr[i] - arr[i - 1]);

	delete [] arr;

	return sum;
}

int	main()
{
	double	result, begin, end;
	double	(*func)(double);

	cout << "Enter low and high limits:" << endl;
	cin >> begin >> end;
	func = sin;
	result = calculate_integral(begin, end, func);
	cout << result;
	return 0;
}