//
// Created by golimghost on 11/16/24.
//

#ifndef ARRAY_H
#define ARRAY_H

#include "libs.h"

class Array {
public:
    int size;
    int capacity;

    Array(int initialCapacity = 1) : size(0), capacity(initialCapacity){
        data = new string[capacity];
    }

    void push_back(string);
    void insert_at(int, string);
    string get_at(int) const;
    void remove_at(int);
    void set_at(int, string) const;
    string print() const;
private:
    string* data;
};

#endif //ARRAY_H
