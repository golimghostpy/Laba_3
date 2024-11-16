#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "libs.h"
#include "OList.h"

class Stack{
private:
    ONode* head;
    ONode* tail;

public:
    Stack() : head(nullptr), tail(nullptr){}

    bool is_empty() const;
    void push(string);
    void pop();
    void print() const;
};

#endif // STACK_H_INCLUDED
