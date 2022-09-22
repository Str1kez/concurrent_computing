#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int arr[12]= {1, 2, 3, 4, 5, -2, 0, 11, 21, 44, 3, -1};
	int arr2[12] = {10, -3, 7, 0, 11, 7, -12, 8, 9, 10, 22, -14};
	int	core_num, s, *sum;

    #pragma omp parallel shared(core_num)
    core_num = omp_get_num_threads();
    sum = new int[core_num];
	s = 0;

    for (int i = 0; i < core_num; i++)
        sum[i] = 0;

    #pragma omp parallel shared(arr, arr2, sum)
    {
        #pragma omp for
        for (int i = 0; i < 12; i++)
            sum[omp_get_thread_num()] = arr[i] + arr2[i];
    }

    for (int i = 0; i < core_num; i++)
        s += sum[i];

    cout << s << endl;

    delete [] sum;
    
    return 0;
}
