cmake_minimum_required(VERSION 3.29)
project(Laba_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /home/golimghost/Desktop/CProj/Laba_3/bin)
include_directories(.)

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
)
