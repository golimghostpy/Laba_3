#include "Queue.h"

bool Queue::is_empty() const{
    return head == nullptr;
}

void Queue::push(string value){
    ONode* new_elem = new ONode(value);

    if (is_empty()){
        head = new_elem;
        tail = new_elem;
        return;
    }

    tail->next = new_elem;
    tail = new_elem;
}

void Queue::pop(){
    if (is_empty()){
        cout << "Queue is empty" << endl;
        return;
    }

    ONode* new_head = head->next;
    cout << "Popped value: " << head->data << endl;
    delete head;
    head = new_head;
}

void Queue::print() const{
    ONode* curr = head;

    while (curr->next != nullptr){
        cout << curr->data << "<-";
        curr = curr->next;
    }
    cout << curr->data << endl;
}
