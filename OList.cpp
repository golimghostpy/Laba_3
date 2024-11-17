#include "OList.h"

bool OList::is_empty() const{
    return first == nullptr;
}

void OList::push_front(string value){
    ONode* new_elem = new ONode(value);

    if(is_empty()){
        first = new_elem;
        last = new_elem;
        ++size;
        return;
    }

    new_elem->next = first;
    first = new_elem;
    ++size;
}

void OList::push_back(string value){
    ONode* new_elem = new ONode(value);

    if(is_empty()){
        first = new_elem;
        last = new_elem;
        ++size;
        return;
    }

    last->next = new_elem;
    last = new_elem;
    ++size;
}

void OList::delete_front(){
    if(is_empty()){
        throw out_of_range("List is empty");
    }

    ONode* toDel = first;
    first = first->next;
    delete toDel;
    --size;
}

void OList::delete_back(){
    if(is_empty()){
        throw out_of_range("List is empty");
    }

    ONode* curr = first;
    while (curr->next != last){
        curr = curr->next;
    }

    last = curr;
    delete curr->next;
    --size;
}

void OList::delete_value(string value) {
    if (is_empty()){
        throw out_of_range("List is empty");
    }

    if (first->data == value) {
        delete_front();
        return;
    }

    ONode* curr = first;
    ONode* prev = nullptr;

    while (curr != nullptr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        throw out_of_range("No such a value");
    }

    if (curr == last) {
        delete_back();
        return;
    }

    prev->next = curr->next;
    delete curr;
    --size;
}

int OList::find_value(string value) const{
    if (is_empty()){
        return -1;
    }

    ONode* curr = first;
    int index = 0;

    while (curr->data != value && curr != last){
        curr = curr->next;
        ++index;
    }

    if (curr->data != value) return -1;

    return index;
}

void OList::print(string delimiter) const{
    if(is_empty()){
        cout << endl;
        return;
    }

    ONode* curr = first;

    while(curr->next != nullptr){
        cout << curr->data << delimiter;
        curr = curr->next;
    }
    cout << curr->data << endl;
}

ONode* OList::find_at(int index) const{
    if(is_empty())
    {
        throw out_of_range("List is empty");
    }
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of range");
    }

    int counter = 0;
    ONode* current = first;
    while (counter < index){
        current = current->next;
        ++counter;
    }
    return current;
}

string OList::join(const char symbol) const{
    string joined;
    ONode* current = first;
    while (current){
        joined += current->data + symbol;
        current = current->next;
    }
    return joined;
}

OList split(const string& str, const string& delimiter) {
    OList result;
    string currentPart;
    int delimiterLength = delimiter.size();

    for (auto i = 0; i < str.size(); ++i) {
        int j = 0;
        while (j < delimiterLength && i + j < str.size() && str[i + j] == delimiter[j]) {
            ++j;
        }

        if (j == delimiterLength) {
            if (currentPart != "") {
                result.push_back(currentPart);
                currentPart = "";
            }
            i += delimiterLength - 1;
        } else {
            currentPart += str[i];
        }
    }

    if (!currentPart.empty()) {
        result.push_back(currentPart);
    }

    return result;
}
