#include "DList.h"

bool TList::is_empty() const{
    return first == nullptr;
}

void TList::push_front(string value){
    TNode* new_elem = new TNode(value);

    if(is_empty()){
        first = new_elem;
        last = new_elem;
        return;
    }

    new_elem->next = first;
    first->prev = new_elem;
    first = new_elem;
}

void TList::push_back(string value){
    TNode* new_elem = new TNode(value);

    if(is_empty()){
        first = new_elem;
        last = new_elem;
        return;
    }

    last->next = new_elem;
    new_elem->prev = last;
    last = new_elem;
}

void TList::delete_front(){
    if(is_empty()){
        cout << "List is empty" << endl;
        return;
    }

    TNode* toDel = first;
    first = first->next;
    delete toDel;
}

void TList::delete_back(){
    if(is_empty()){
        cout << "List is empty" << endl;
        return;
    }

    TNode* toDel = last;
    last = last->prev;
    delete toDel;
}

void TList::delete_value(string value){
    if (is_empty()){
        cout << "No such a value" << endl;
        return;
    }

    if (first->data == value) {
        delete_front();
        return;
    }

    TNode* curr = first;

    while (curr != nullptr && curr->data != value) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "No such a value" << endl;
        return;
    }

    if (curr == last) {
        delete_back();
        return;
    }

    curr->prev->next = curr->next;
    delete curr;
    --size;
}

int TList::find_value(string value) const{
    TNode* curr = first;
    int index = 0;

    while (curr->data != value && curr != nullptr){
        curr = curr->next;
        ++index;
    }

    if (curr == nullptr) {
        return -1;
    }
    return index;
}

void TList::print(string delimiter) const{
    TNode* curr = first;
    while(curr->next != nullptr){
        cout << curr->data << delimiter;
        curr = curr->next;
    }
    cout << curr->data << endl;
}