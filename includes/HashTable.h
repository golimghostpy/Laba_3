#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include "libs.h"
#include "OList.h"
#include "Array.h"

struct HashBlock{
    string key;
    string value;
    HashBlock* next;

    HashBlock(string val1, string val2) : key(val1), value(val2), next(nullptr){}
};

class HashList{
public:
    HashBlock* first;

    HashList() : first(nullptr){}

    bool is_empty() const;
    void push_back(string, string);
    void delete_value(string);
    void print(string) const;
};

struct HashBucket{
    int key;
    HashList data;

    HashBucket() : key(0) {}
    HashBucket(int val) : key(val){}
};

class HashTable{
private:
    int capacity;

public:
    int size;
    HashBucket* data;

    HashTable(int initialCapacity = 30) : size(0), capacity(initialCapacity){
        data = new HashBucket[capacity];
    }

    void set(string, string);
    string get_values(string) const;
    void delete_value(const string&);
    void print() const;
};

int hash_find(const string&);

#endif // HASHTABLE_H_INCLUDED
