project(concurent_computing/single_computing)

cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})

set(CMAKE_CXX_STANDARD ${CMAKE_LANGUAGE_VERSION})

# for windows
add_compile_options(/W4 /WX /openmp)

#add_compile_options(-Wall -Wextra -pedantic -Werror)

#add_executable(array_sum array_sum.cpp utils/array_tools.h utils/array_io.cpp)
#add_executable(arrays_sum arrays_sum.cpp utils/array_tools.h utils/array_io.cpp)
#add_executable(integral integral_calculation.cpp utils/array_tools.h utils/array_io.cpp)
#add_executable(bubble_sort bubble_sort.cpp utils/array_tools.h utils/array_io.cpp)
#add_executable(elements_matrix_sum matrix_sum.cpp utils/array_tools.h utils/array_io.cpp)
#add_executable(matrix_transpose matrix_transpose.cpp utils/array_tools.h utils/array_io.cpp)
add_executable(matrix_multiply matrix_multiply.cpp utils/array_tools.h utils/array_io.cpp)
