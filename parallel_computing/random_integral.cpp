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
	const double	a = 0, b = 1, M = 0.4;
	const int		amount = 1000;
	bool 			*marks;

	sum = 0;
	y_points = new double [amount];
	x_points = new double [amount];
	marks = new bool [amount];
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist_y(0, M);

    #pragma omp parallel shared(x_points, y_points, marks)
    {
        #pragma omp for
        for (int i = 0; i < amount; i++)
		{
			x_points[i] = a + (b - a) / amount * i;
			y_points[i] = dist_y(mt);
			marks[i] = func(x_points[i]) >= y_points[i];
		}
    }

    for (int i = 0; i < amount; i++)
		sum += marks[i];

	cout << "Area under line = " << sum / amount * (b - a) * M << endl;

	delete [] x_points;
	delete [] y_points;
	delete [] marks;
    return 0;
}
