#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "libs.h"
#include "OList.h"

class Stack{
public:
    ONode* head;
    ONode* tail;

    Stack() : head(nullptr), tail(nullptr){}

    bool is_empty() const;
    void push(string);
    void pop();
    string get_head() const;
    string print() const;
};

#endif // STACK_H_INCLUDED
