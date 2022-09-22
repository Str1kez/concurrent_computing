project(concurent_computing/parallel_computing)

cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})

set(CMAKE_CXX_STANDARD ${CMAKE_LANGUAGE_VERSION})

# for windows
add_compile_options(/W4 /WX /openmp)

#add_compile_options(-Wall -Wextra -pedantic -Werror -fopenmp)

#add_executable(sum sum.cpp)
add_executable(sum_in_arr sum_in_arr.cpp)
#add_executable(integral_by_random_points random_integral.cpp)
