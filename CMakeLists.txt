cmake_minimum_required(VERSION 3.27)
PROJECT(AlgosApp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(cunit/CUnit)

add_executable(algos_app
                algos/runner.c 
                algos/array_util.c
                algos/vector.c
                algos/quicksort.c
                algos/binary_tree.c
                algos/linked_list.c)
target_link_libraries(algos_app PRIVATE cunit)
