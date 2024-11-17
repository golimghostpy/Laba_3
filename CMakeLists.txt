cmake_minimum_required(VERSION 3.29)
project(Laba_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /home/golimghost/Desktop/CProj/Laba_3/bin)
include_directories(.)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

enable_testing()
add_subdirectory(googletest)

add_executable(main
        main.cpp
        Array.cpp
        Array.h
        OList.h
        OList.cpp
        DList.h
        DList.cpp
        Queue.h
        Queue.cpp
        Stack.h
        Stack.cpp
        HashTable.h
        HashTable.cpp
        AVLTree.h
        AVLTree.cpp
        libs.h
        testing.cpp
        testing.h
)

target_link_libraries(main gtest_main)
