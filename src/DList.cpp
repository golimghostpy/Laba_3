#include "../includes/DList.h"

bool TList::is_empty() const{
    return first == nullptr;
}

void TList::push_front(string value){
    TNode* new_elem = new TNode(value);

    if(is_empty()){
        first = new_elem;
        last = new_elem;
        ++size;
        return;
    }

    new_elem->next = first;
    first->prev = new_elem;
    first = new_elem;
    ++size;
}

void TList::push_back(string value){
    TNode* new_elem = new TNode(value);

    if(is_empty()){
        first = new_elem;
        last = new_elem;
        ++size;
        return;
    }

    last->next = new_elem;
    new_elem->prev = last;
    last = new_elem;
    ++size;
}

void TList::delete_front(){
    if(is_empty()){
        throw out_of_range("List is empty");
    }

    TNode* toDel = first;
    first = first->next;
    --size;
    delete toDel;
}

void TList::delete_back(){
    if(is_empty()){
        throw out_of_range("List is empty");
    }

    TNode* toDel = last;
    last = last->prev;
    --size;
    delete toDel;
}

void TList::delete_value(string value){
    if (is_empty()){
        throw out_of_range("List is empty");
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
        throw out_of_range("No such a value");
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
    if (is_empty()){
        return -1;
    }

    TNode* curr = first;
    int index = 0;

    while (curr->data != value && curr != last){
        curr = curr->next;
        ++index;
    }

    if (curr->data != value) return -1;

    return index;
}

string TList::print(string delimiter) const{
    string result;
    TNode* curr = first;
    while(curr->next != nullptr){
        result += curr->data + delimiter;
        curr = curr->next;
    }
    result += curr->data + "\n";
    return result;
}

TNode* TList::find_at(int index) const{
    if(is_empty())
    {
        throw out_of_range("List is empty");
    }
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of range");
    }

    int counter = 0;
    TNode* current = first;
    while (counter < index){
        current = current->next;
        ++counter;
    }
    return current;
}