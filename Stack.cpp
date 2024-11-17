#include "Stack.h"

bool Stack::is_empty() const{
    return head == nullptr;
}

void Stack::push(string value){
    ONode* new_elem = new ONode(value);

    if(is_empty()){
        head = new_elem;
        tail = new_elem;
    }

    new_elem->next = head;
    head = new_elem;
}

void Stack::pop(){
    if (is_empty()){
        throw out_of_range("Stack is empty");
    }

    ONode* new_head = head->next;
    cout << "Popped value: " << head->data << endl;
    delete head;
    head = new_head;
}

string Stack::get_head() const
{
    return head->data;
}

void Stack::print() const{
    if (head == nullptr) return;

    ONode* curr = head;

    while(curr != tail){
        cout << curr->data << "->";
        curr = curr->next;
    }

    cout << curr->data << endl;
}