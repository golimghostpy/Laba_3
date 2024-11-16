#ifndef OLIST_H_INCLUDED
#define OLIST_H_INCLUDED

#include "libs.h"

struct ONode{
    string data;
    ONode* next;

    ONode(string val) : data(val), next(nullptr){}
};

class OList{
private:
    int size;
    ONode* first;
    ONode* last;

public:
    OList() : size(0), first(nullptr), last(nullptr){}

    bool is_empty() const;
    void push_front(string);
    void push_back(string);
    void delete_front();
    void delete_back();
    void delete_value(string);
    int find_value(string) const;
    void print(string) const;
    ONode* find_at(int) const;
    string join(const char) const;
};

void olist_do(const string&, OList&);
OList split(const string&, const string&);

#endif // OLIST_H_INCLUDED
