#include "../includes/Array.h"

void Array::push_back(string element) {
    if (size == capacity) {
        capacity *= 2;
        string* newData = new string[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = element;
}

void Array::insert_at(int index, string element) {
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range");
    }
    if (size == capacity) {
        capacity *= 2;
        string* newData = new string[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    ++size;
}

string Array::get_at(int index) const{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

void Array::remove_at(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    --size;
}

void Array::set_at(int index, string element) const{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    data[index] = element;
}

string Array::print() const{
    string result;

    for (int i = 0; i < size; i++) {
        result += data[i] + " ";
    }
    result += "\n";
    return result;
}