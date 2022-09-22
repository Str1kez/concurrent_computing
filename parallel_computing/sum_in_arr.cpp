#include <iostream>

using namespace std;

int main()
{
    int arr[12] = {1, 2, 3, 4, 5, -2, 0, 11, 21, 44, 3, -1};
    int arr2[12] = {10, -3, 7, 0, 11, 7, -12, 8, 9, 10, 22, -14};
    int sum[12];
    #pragma omp parallel shared(arr, arr2, sum)
    {
        #pragma omp for
        for (int i = 0; i < 12; i++)
            sum[i] = arr[i] + arr2[i];
    }

    for (int i = 0; i < 12; i++)
        cout << sum[i] << '\t';
    cout << endl;
    
    return 0;
}
