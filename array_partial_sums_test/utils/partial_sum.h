#ifndef CONCURRENT_COMPUTING_PARTIAL_SUM_H
#define CONCURRENT_COMPUTING_PARTIAL_SUM_H

long long int	*partial_sum(const long long int *array, unsigned int size);
long long int	*partial_sum_hybrid(const long long int *array, unsigned int size, unsigned int thread_num = 3);
long long int	*partial_sum_parallel(const long long int *array, unsigned int size, unsigned int thread_num = 3);

#endif
