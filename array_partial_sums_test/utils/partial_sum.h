#ifndef CONCURRENT_COMPUTING_PARTIAL_SUM_H
#define CONCURRENT_COMPUTING_PARTIAL_SUM_H

int *partial_sum(const int *array, int size);
int *partial_sum_hybrid(const int *array, int size, unsigned int thread_num = 3);
int *partial_sum_parallel(const int *array, int size, unsigned int thread_num = 3);

#endif
