//
// Created by golimghost on 11/16/24.
//

#ifndef ARRAY_H
#define ARRAY_H

#include "libs.h"

class Array {
public:
    Array(int initialCapacity = 10) : size(0), capacity(initialCapacity){
        data = new string[capacity];
    }

    void push_back(string);
    void insert_at(int, string);
    string get_at(int) const;
    void remove_at(int);
    void set_at(int, string) const;
    void print() const;
private:
    string* data;
    int size;
    int capacity;
};

#endif //ARRAY_H
