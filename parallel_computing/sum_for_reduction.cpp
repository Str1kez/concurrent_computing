#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int arr[12]= {1, 2, 3, 4, 5, -2, 0, 11, 21, 44, 3, -1};
	int arr2[12] = {10, -3, 7, 0, 11, 7, -12, 8, 9, 10, 22, -14};
	int	s;
    
	s = 0;

    #pragma omp parallel for shared(arr, arr2) reduction(+: s)
    for (int i = 0; i < 12; i++)
        s += arr[i] + arr2[i];

    cout << s << endl;
    
    return 0;
}
