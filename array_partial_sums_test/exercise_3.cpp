#include <iostream>
#include "utils/array_tools.h"
#include "utils/partial_sum.h"

using namespace std;

int main()
{
    int size, *array, *array_temp;
    cout << "Enter size of array: \t";
    cin >> size;
    array = array_create_random(size);
    cout << "Origin array:" << endl;
    array_output(array, size);

    array_temp = partial_sum_hybrid(array, size);

    cout << "Array of partial sum:" << endl;
    array_output(array_temp, size);
    delete[] array;
    delete[] array_temp;
    return 0;
}
