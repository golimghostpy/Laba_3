cmake_minimum_required(VERSION 3.29)
project(Laba_3)

set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/local/include)
include_directories(/includes)

add_executable(serial
        serial.cpp
        src/Array.cpp
        src/AVLTree.cpp
        src/DList.cpp
        src/HashTable.cpp
        src/OList.cpp
        src/Queue.cpp
        src/Stack.cpp
)

add_executable(lb3 src/main.cpp)

add_library(realisation
        src/Array.cpp
        src/AVLTree.cpp
        src/DList.cpp
        src/HashTable.cpp
        src/OList.cpp
        src/Queue.cpp
        src/Stack.cpp)

enable_testing()
add_executable(tests tests/testing.cpp)
target_link_libraries(tests gtest gtest_main realisation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
