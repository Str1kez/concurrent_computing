project(concurent_computing/array_partial_sums_test)

cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})

set(CMAKE_CXX_STANDARD ${CMAKE_LANGUAGE_VERSION})

# for windows
#add_compile_options(/W4 /WX /openmp)

#for linux clang++
add_compile_options(-openmp -Wall -Wextra -pedantic)
#add_executable(sum sum.cpp)
add_executable(partial_sum_parallel exercise_1.cpp utils/array_io.cpp)
#add_executable(sum_for_reduction sum_for_reduction.cpp)
#add_executable(integral_by_random_points random_integral.cpp)
