project(concurent_computing/parallel_computing)

cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})

set(CMAKE_CXX_STANDARD ${CMAKE_LANGUAGE_VERSION})

#for windows
#add_compile_options(/W4 /WX /openmp)

#for gcc
#add_compile_options(-Wall -Wextra -pedantic -Werror -fopenmp)

#for clang
add_compile_options(-openmp -Wall -Wextra -pedantic -Werror)

#add_executable(sum sum.cpp)
#add_executable(sum_in_arr sum_in_arr.cpp)
add_executable(sum_block sum_block.cpp)
#add_executable(integral_by_random_points random_integral.cpp)
