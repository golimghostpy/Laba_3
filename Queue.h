#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "libs.h"
#include "OList.h"

class Queue{
private:
    ONode* head;
    ONode* tail;

public:
    Queue() : head(nullptr), tail(nullptr){}

    bool is_empty() const;
    void push(string);
    void pop();
    void print() const;
};

#endif // QUEUE_H_INCLUDED
