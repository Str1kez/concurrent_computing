//
// Created by vazin on 03.09.2022.
//

#ifndef CONCURENT_COMPUTING_ARRAY_TOOLS_H
#define CONCURENT_COMPUTING_ARRAY_TOOLS_H

int		*array_create(unsigned int size);
void	array_output(const int *arr, unsigned int size);
int		**matrix_create(unsigned int row_size, unsigned int column_size);
void	matrix_delete(int **matrix, unsigned int column_size);
void 	matrix_output(int **matrix, unsigned int row_size, unsigned int column_size);
int		**matrix_init(unsigned int row, unsigned int column);
void	generate_matrix(int **matrix, unsigned int row, unsigned int column);

#endif //CONCURENT_COMPUTING_ARRAY_TOOLS_H
