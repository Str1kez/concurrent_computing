#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int arr[12]= {1, 2, 3, 4, 5, -2, 0, 11, 21, 44, 3, -1};
	int arr2[12] = {10, -3, 7, 0, 11, 7, -12, 8, 9, 10, 22, -14};
	int	core_num, s;

    // #pragma omp parallel shared(core_num)
    // core_num = omp_get_num_threads();
    core_num = 3;
	s = 0;

    #pragma omp parallel shared(arr, arr2) num_threads(core_num) reduction(+: s)
    {
        int id = omp_get_thread_num(), num_threads = omp_get_num_threads();
        for (int i = id; i < 12; i += num_threads)
            s += arr[i] + arr2[i];
    }

    cout << s << endl;
    
    return 0;
}
