#include <iostream>
#include <random>
#include <cmath>

using namespace std;

double func(double x)
{
	return sin(x);
}

int main()
{
	double			*y_points, *x_points, sum;
	const double	a = 0, b = 1, M = 1;
	const int		amount = 10000;

	sum = 0;
	y_points = new double [amount];
	x_points = new double [amount];
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist_x(a, b);
	uniform_real_distribution<double> dist_y(0, M);

	#pragma omp parallel for shared(x_points, y_points) reduction(+: sum)
	for (int i = 0; i < amount; i++)
	{ 
		x_points[i] = dist_x(mt);
		y_points[i] = dist_y(mt);
		sum += func(x_points[i]) >= y_points[i];
	}

	cout << "Area under line = " << sum / amount * (b - a) * M << endl;

	delete [] x_points;
	delete [] y_points;
	return 0;
}
