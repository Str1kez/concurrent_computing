//
// Created by vazin on 03.09.2022.
//

#ifndef CONCURRENT_COMPUTING_ARRAY_TOOLS_H
#define CONCURRENT_COMPUTING_ARRAY_TOOLS_H

long long int	*array_create(unsigned int size);
long long int	*array_create_random(unsigned int size);
void			array_output(const long long int *arr, unsigned int size);
unsigned int	get_level();

#endif // CONCURRENT_COMPUTING_ARRAY_TOOLS_H
