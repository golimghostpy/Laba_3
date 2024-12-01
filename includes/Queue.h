#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "libs.h"
#include "OList.h"

class Queue{
public:
    ONode* head;
    ONode* tail;

    Queue() : head(nullptr), tail(nullptr){}

    bool is_empty() const;
    void push(string);
    void pop();
    string get_head() const;
    string print() const;
};

#endif // QUEUE_H_INCLUDED
